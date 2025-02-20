#include "mfeTexture.h"
#include "mfeApplication.h"

//메인 함수에서 선언한 전역 변수가 메모리 상에 존재하는데 이쪽에서는 모르기 때문에 extern을 사용하여 전역 변수의 존재를 알릴 수 있다.
//이러면 이 파일에서도 메인 함수에 선언된 전역 변수를 사용할 수 있게 된다.
//이렇게 전역 변수를 다른 파일에서 가져와 쓰려면 extern 키워드를 통해 파일에 가르쳐 주면 된다는 것을 기억해야 한다.
//extern - 해당 전역 변수가 존재함을 알리는 키워드
extern mfe::Application application;  //비트맵을 활용하기 위해 필요

namespace mfe::graphics {
	//이렇게 부모 생성자를 호출하지 않으면 오류가 발생하게 된다.
	//그 이유는 상속받은 부모 클래스가 추상 클래스이기 때문에 따로 생성자 호출이 되지 않아서 오류가 발생하기 때문이다.
	//다음과 같이 부모 것을 통채로 초기화시킬 때는 생성자를 호출하면 되는 것이다.
	Texture::Texture()
		: Resource(enums::eResourceType::Texture)
	{
	}

	HRESULT Texture::Load(const std::wstring& path)
	{
		//우리는 파일의 종류를 구분해서 사용해야 하는데 이때 우리가 가지고 있는 것은 path를 통해 넘어온 경로이다.
		//그리고 우리는 이 경로의 맨 마지막은 파일의 이름과 확장자가 함께 있다는 것을 알고 있다. 그래서 이 경로를 이용하여 로드할 파일의 확장자를 알아내야 한다.
		//std::wstring ext = path.substr(path.find_last_of(L".") + 1); 라는 문법을 사용하면 우리가 원하는 확장자를 구할 수 있다.
		//여기서 ext는 확장자라는 뜻이고 path.find_last_of(L".") + 1은 인자로 건네준 L"."을 찾고 여기서 + 1을 한 위치부터 끝까지의 값을 찾는다.
		//그리고 path.substr()은 path.find_last_of(L".") + 1가 찾은 값을 반환한다.(substr함수는 문자열의 일부를 리턴하는 함수이다.)
		//이렇게 해서 ext에는 파일의 확장자명을 저장할 수 있다.
		//path.find_last_of(L".")는 path 문자열에서 .을 찾고 찾은 .부터 문자열의 끝까지 찾아 반환한다.
		//그렇기 때문에 .을 빼고 확장자명만을 가지고 오고 싶으니 +1을 해주어 .바로 뒤부터 끝까지의 문자열을 찾아 반환하게 된다.

		std::wstring ext = path.substr(path.find_last_of(L".") + 1);  //확장자명을 가지고 오는 구문
		//bmp 일 때
		if (ext == L"bmp") {
			mType = eTextureType::Bmp;
			//경로에 있는 비트맵 파일을 가지고 오는 것은 살짝 복잡한데 아래와 같이 LoadImageW함수를 써서 해당 파일을 비트맵에 저장한다.
			//첫 번째 인자는 인스턴스로 그냥 nullptr을 넣으면 되는데 두 번째 인자는 경로를 받게 된다.
			//경로를 LPCWSTR 타입으로 받는데 이게 무슨 자료형이냐 하면 WCHAR(wchar_t)의 포인터형으로 std::wstring객체는 문자열 배열 뿐 아니라 길이 정보 등의 여러 정보를
			//가지고 있는데 이 중 문자열 배열만을 가지고 오라는 의미의 자료형이다.(즉, wstring의 실제 주소를 가지고 오라는 의미)
			//이것을 만족하는 것이 바로 wstring의 c_str()함수로 이 함수의 반환형이 wchar_t*이다.
			//그리고 세 번째 인자로는 타입을 받게 되는데 다음과 같이 IMAGE_BITMAP 타입으로 받는다 하면 된다.
			//네 다섯 번째 인자는 그냥 0을 넣으면 되고 마지막 인자는 다음과 같이 넣으면 된다.(자세한 것은 차차 알기로 하고 여기서는 그냥 이렇게 하면 된다는 것만 알아가자.)
			//그런데 LoadImageW 함수는 반환형이 HANDLE이라 그냥 대입하면 오류가 발생하게 되기에 HBITMAP으로 형 변환을 해주고 대입해주어야 한다.
			//이렇게 png파일에 비해서 조금 더 까다로운 방식이지만 속도는 이게 살짝 더 빠르다.
			mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

			if (mBitmap == nullptr)   //뭔가 잘 안 되어서 로드가 안 되었다면 비트맵은 nullptr을 가지게 된다.
				return S_FALSE;  //반환형인 HRESULT에 맞게 반환값도 HRESULT형을 지정(S_OK값은 0L(참) S_FALSE값은 1L(거짓))
			
			//잘 로드가 되면 문제없이 이미지 파일을 비트맵 형태로 가지고 있을 것이니 아래와 같이 진행.
			BITMAP info = {};  //비트맵 정보를 저장할 변수
			//이 함수는 첫 번째 인자로 전달받은 비트맵으로부터 두 번째 인자로 전달받은 크기만큼 세 번째 인자로 전달된 인자에 데이터를 가져와 넣어주는 함수이다.
			//이때 알 수 있는 것은 세 번째 인자는 주소 즉, 포인터를 받는데 이를 통해 내부에서 값을 바꾸어서 빠져나간다는 것을 알 수 있다.
			//이 함수는 return을 대신하여 세 번째 인자에 값을 전달하는 방식을 가지고 있다.
			GetObject(mBitmap, sizeof(BITMAP), &info);  

			mWidth = info.bmWidth;
			mHeight = info.bmHeight;

			//버퍼 하나당 dc 하나를 사용한다는 것을 지난 백버퍼 수업에서 배웠다.
			//지금까지의 과정은 이미지만 로드해서 가져온 것이다. 이 이미지를 사용할 때 백버퍼를 사용할 때와 마찬가지로 비트맵과 짝을 이루는 dc가 필요하다.
			//왜냐하면, 비트맵 이미지를 출력해 주기 위해서는 dc가 있어야 하기 때문이다.
			//비트맵 하나당 dc 파일 하나로 짝을 이루고 있어야만 이미지 출력이 가능하다.
			//그렇기 때문에 dc를 하나 새로 만들어주어야 한다.
			HDC mainDC = application.GetHdc();  //메인 dc를 가져와서 저장
			mHdc = CreateCompatibleDC(mainDC);  //메인 dc를 활용해서 새 dc 생성

			//위와 같이 새 dc가 만들어지는 순간 그 안엔 안 쓰는 하얀색 도화지(빈 비트맵)이 있게 된다.
			//그럼 이제 새로 만든 dc와 불러온 이미지 파일을 엮어주어야 한다.
			HBITMAP oldBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);  //새로 만든 dc에 불러온 이미지 파일(비트맵)을 적용하면서 기존에 dc 안에 있던 빈 비트맵을 저장
			DeleteObject(oldBitmap);  //기존에 dc 안에 있던 빈 비트맵은 필요없으니 dc에서 완전히 삭제(남겨두면 계속 남아서 메모리 손실 발생하니 필요없으면 바로 삭제해주어야 한다.)
		}

		//png 일 때
		else if (ext == L"png") {
			mType = eTextureType::Png;
			mImage = Gdiplus::Image::FromFile(path.c_str());

			if (mImage == nullptr)
				return S_FALSE;  //이미지 로드를 실패했음을 알리기 위해 S_FALSE를 반환

			mWidth = mImage->GetWidth();
			mHeight = mImage->GetHeight();
		}

		return S_OK;  //성공적으로 이미지 로드를 마쳤음을 알리는 S_OK를 반환
	}

	Texture::~Texture()
	{
	}
}