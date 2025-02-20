#pragma once
#include "mfeEntity.h"
#include "mfeComponent.h"
#include "mfeTexture.h"

//게임 오브젝트의 render를 관장하는 컴포넌트
namespace mfe {
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		//void ImageLoad(const std::wstring& path);  //이것 또한 이미지를 호출하는 함수이기에 이미지 리소스와 관련되어 있으므로 텍스쳐 클래스로 옮긴다.

		void SetTexture(graphics::Texture* texture) {
			mTexture = texture;
		}

		void SetSize(math::Vector2 size) {
			mSize = size;
		}

		~SpriteRenderer();
	private:
		//이제 아래의 이미지 관련된 것들은 모두 컴포넌트가 아닌 리소스에서 관리할 것이기에 이미지 리소스를 관리하는 텍스쳐 클래스로 옮긴다.
		//Gdiplus::Image* mImage;
		//UINT mWidth;
		//UINT mHeight;

		//텍스쳐 리소스를 사용하기 위해서 이를 저장할 변수 선언
		graphics::Texture* mTexture;
		math::Vector2 mSize;  //이 변수는 텍스쳐 리소스의 크기를 저장한다.(리소스를 변수에 저장된 크기만큼 축소나 확대하여 출력할 수 있도록 하기 위해 필요하다.)
	};
}
