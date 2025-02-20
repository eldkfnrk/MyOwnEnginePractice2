#pragma once
#include "mfeEntity.h"
#include "mfeComponent.h"
#include "mfeTexture.h"

//���� ������Ʈ�� render�� �����ϴ� ������Ʈ
namespace mfe {
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		//void ImageLoad(const std::wstring& path);  //�̰� ���� �̹����� ȣ���ϴ� �Լ��̱⿡ �̹��� ���ҽ��� ���õǾ� �����Ƿ� �ؽ��� Ŭ������ �ű��.

		void SetTexture(graphics::Texture* texture) {
			mTexture = texture;
		}

		void SetSize(math::Vector2 size) {
			mSize = size;
		}

		~SpriteRenderer();
	private:
		//���� �Ʒ��� �̹��� ���õ� �͵��� ��� ������Ʈ�� �ƴ� ���ҽ����� ������ ���̱⿡ �̹��� ���ҽ��� �����ϴ� �ؽ��� Ŭ������ �ű��.
		//Gdiplus::Image* mImage;
		//UINT mWidth;
		//UINT mHeight;

		//�ؽ��� ���ҽ��� ����ϱ� ���ؼ� �̸� ������ ���� ����
		graphics::Texture* mTexture;
		math::Vector2 mSize;  //�� ������ �ؽ��� ���ҽ��� ũ�⸦ �����Ѵ�.(���ҽ��� ������ ����� ũ�⸸ŭ ��ҳ� Ȯ���Ͽ� ����� �� �ֵ��� �ϱ� ���� �ʿ��ϴ�.)
	};
}
