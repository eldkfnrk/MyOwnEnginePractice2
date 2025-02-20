#include "mfeSpriteRenderer.h"
#include "mfeGameObject.h"
#include "mfeTransform.h"

namespace mfe {
	//이 함수의 정의한 내용은 텍스쳐 클래스의 Load함수에 복사(여기의 ImageLoad함수 역할을 그곳의 Load함수가 대신하게 된다.)
	//void SpriteRenderer::ImageLoad(const std::wstring& path)
	//{
	//	mImage = Gdiplus::Image::FromFile(path.c_str());
	//	mWidth = mImage->GetWidth();
	//	mHeight = mImage->GetHeight();
	//}

	SpriteRenderer::SpriteRenderer()
		: Component(), mTexture(nullptr), mSize(Vector2::One)
	{

	}

	void SpriteRenderer::Initialize()
	{

	}

	void SpriteRenderer::Update()
	{

	}

	void SpriteRenderer::LateUpdate()
	{

	}

	void SpriteRenderer::Render(HDC hdc)
	{
		//Transform* tr = GetOwner()->GetComponent<Transform>();
		//Vector2 pos = tr->GetPosition();
		//
		//Gdiplus::Graphics graphics(hdc);
		//graphics.DrawImage(mImage, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));

		//화면에 리소스를 활용하여 출력
		//위의 동작은 png파일 리소스를 활용하는 코드로 작성하는 것이다.
		//화면에 출력하는 방법에는 두 가지가 있는데 첫 번째는 리소스 관리하는 클래스에서 출력하는 것 그리고 두 번째는 스프라이트렌더러에서 출력하는 것이다.
		//그러나 출력에 있어서는 위치 정보를 가지는 트랜스펌 컴포넌트가 반드시 필요한데 리소스 관리하는 클래스에는 컴포넌트를 굳이 추가해서 리소스마다 컴포넌트를 받을 필요도 없고
		//그렇게 하는 것보다 이 컴포넌트에서 진행하는 것이 조금 더 효율적으로 진행할 수 있기에 이렇게 진행하는 것이다.
		//그리고 리소스는 리소스만을 관리하고 출력과 같은 동작들은 컴포넌트에서 하는 것이 구분도 되고 진행하는데 헷갈리지 않고 원할하게 돌아갈 수 있다.

		if (mTexture == nullptr) {  //만약 텍스쳐 리소스가 없다면(텍스쳐 세팅 필요)
			assert(false);  //오류 메시지 박스를 띄워주고 강제 종료(assert가 호출되면 프로그램 종료와 동시에 호출된 함수의 위치로 이동시켜 주기 때문에 무슨 문제인지 파악하고 바로 해결해주어야 한다.)
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Bmp) {
			//이 함수는 이미지의 특정 색을 투명하게 적용시켜 화면에 출력해주는 함수이다.
			//이게 무슨 의미이냐 하면 비트맵은 투명 값이 없다. 그러니까 더 자세히 설명하면 비트맵은 특정 사용할 이미지들의 모음으로 되어 있는 파일로 이는 예시 파일을 확인해보면 더 자세히 알 수 있다.
			//아무튼 그렇게 모여있는 이미지들 중에서 하나의 이미지를 잘라서 출력을 하고 싶은데 앞에서 말했듯이 비트맵은 투명 값이 없으니 정확하게 사용할 이미지만 자르는 것은 불가능하여 배경색이 남게 된다.
			//그렇게 되면 이미지 뒤에 다른 배경이 있어 게임의 완성도가 최악으로 떨어지게 되는데 이를 해결하기 위해서 있는 것이 바로 이 함수이다. 이 함수는 비트맵을 잘랐을 때 특정 색을 투명화시켜 주기
			//때문에 배경색만 투명화시켜 원할한 이미지 출력을 가능하게 해준다.
			//일단 이 함수의 첫 번째 인자는 출력할 위치의 dc이고 두 세 번째 인자는 이미지를 출력할 위치이고 네 다섯 번째 인자는 이미지의 너비와 높이이고 여섯 번째 인자는 이미지의 핸들(dc)이다.
			//그리고 일곱 여덟 번째 인자는 가져올 이미지의 시작 지점이고 아홉 열 번째 인자는 원본 이미지에서 시작 지점부터 잘라낼 이미지의 너비와 높이이며 마지막 인자는 투명하게 할 색상(RGB)이다.
			//이 정보는 아래 블로그에서 적혀있는 내용을 그대로 적은 것이기에 더 보기 쉽고 자세히 알려면 아래 블로그 주소로 들어가 보면 된다.
			//https://blog.naver.com/power2845/50147965306
			//이번에는 비트맵을 출력하는 것을 확인하기 위해 원본 전체를 출력
			//보통 비트맵의 배경색은 마젠타 색(RGB(255,0,255))을 쓴다. 왜냐하면, 이 색이 리소스 이미지 자체에 존재할 확률이 아주 적기 때문이다.(아마 들어있을 확률이 가장 낮은 색이다.)
			TransparentBlt(hdc, pos.x, pos.y, mTexture->GetWidth(), mTexture->GetHeight(), mTexture->GetHdc(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight(), RGB(255, 0, 255));

			//비트맵을 자르는 기능은 나중에 추가해주실 예정
		}
		else if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Png) {
			Gdiplus::Graphics graphics(hdc);
			graphics.DrawImage(mTexture->GetImage(), Gdiplus::Rect(pos.x, pos.y, mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y));
		}
	}

	SpriteRenderer::~SpriteRenderer()
	{
	}
}