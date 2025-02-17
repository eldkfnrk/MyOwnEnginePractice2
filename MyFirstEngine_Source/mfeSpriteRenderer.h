#pragma once
#include "mfeComponent.h"

//게임 오브젝트의 render를 관장하는 컴포넌트
namespace mfe {
	class SpriteRenderer : public Component
	{
	private:
		Gdiplus::Image* mImage;
		UINT mWidth;
		UINT mHeight;

	public:
		SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void ImageLoad(const std::wstring& path);

		~SpriteRenderer();
	};
}
