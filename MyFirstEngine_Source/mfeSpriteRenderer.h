#pragma once
#include "mfeComponent.h"

//���� ������Ʈ�� render�� �����ϴ� ������Ʈ
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
