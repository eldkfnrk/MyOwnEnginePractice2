#pragma once
#include "mfeResource.h"

namespace mfe::graphics {  //그래픽스 관련된 것들을 모으는 네임스페이스 안 네임스페이스(조금 더 역할군에 맞게 쪼개 놓은 것일 뿐 큰 의미가 있는 것은 아니다.)
	//그러나 이렇게 역할군끼리 모아놓으면 무엇을 위해 있는 것인지 알기 쉽게 정리가 되고 가독성이 좋게 되니 나누는 것도 좋은 방법이다.
	//그리고 이렇게 우리가 만드는 클래스 외에도 이미 WinAPi나 C++이 정의한 동일한 이름의 것들이 있을 수도 있으니 이것들을 구분하기 위해서 사용하는 것도 있다.
	class Texture : public Resource
	{
	public:
		enum class eTextureType {  //텍스쳐 파일의 형태도 여러 가지가 있으므로 이미지 로드를 할 때 이를 구분하기 위한 enum class
			Bmp,
			Png,
			None,
		};
	
		Texture();

		HRESULT Load(const std::wstring& path) override;

		UINT GetWidth() {
			return mWidth;
		}
		UINT GetHeight() {
			return mHeight;
		}
		HDC GetHdc() {
			return mHdc;
		}
		eTextureType GetTextureType() {
			return mType;
		}
		Gdiplus::Image* GetImage() {
			return mImage;
		}

		~Texture();

	private:
		eTextureType mType;
		//(bmp - 24비트 파일, png - 32비트 파일)
		Gdiplus::Image* mImage;  //png파일을 그릴 때는 이와 같이 Gdiplus의 이미지 객체를 활용
		HBITMAP mBitmap;  //bmp파일을 그릴 때는 비트맵 활용
		HDC mHdc;  //더블 버퍼링 했을 때 비트 맵 만들고 띄어줄 dc가 따로 있었기 때문에 여기서도 비트맵을 활용할 때 따로 띄어줄 dc가 필요하다.

		//이와 같이 비트맵을 활용할 때는 조금 더 까다로운 부분이 있다. 그래서 이를 보완한 것이 Gdiplus이고 비트맵과 dc를 함께 쓰는 것을 Gdi라 한다.
		//비트맵과 dc는 짝으로 무조건 함께 사용되어야 한다.

		UINT mWidth;
		UINT mHeight;
	};
}