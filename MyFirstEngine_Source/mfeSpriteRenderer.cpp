#include "mfeSpriteRenderer.h"
#include "mfeGameObject.h"
#include "mfeTransform.h"
#include "mfeRenderer.h"

namespace mfe {
	//�� �Լ��� ������ ������ �ؽ��� Ŭ������ Load�Լ��� ����(������ ImageLoad�Լ� ������ �װ��� Load�Լ��� ����ϰ� �ȴ�.)
	//void SpriteRenderer::ImageLoad(const std::wstring& path)
	//{
	//	mImage = Gdiplus::Image::FromFile(path.c_str());
	//	mWidth = mImage->GetWidth();
	//	mHeight = mImage->GetHeight();
	//}

	SpriteRenderer::SpriteRenderer()
		: Component(enums::eComponentType::SpriteRenderer), mTexture(nullptr), mSize(Vector2::One)
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
		if (mTexture == nullptr) {  //���� �ؽ��� ���ҽ��� ���ٸ�(�ؽ��� ���� �ʿ�)
			assert(false);  //���� �޽��� �ڽ��� ����ְ� ���� ����(assert�� ȣ��Ǹ� ���α׷� ����� ���ÿ� ȣ��� �Լ��� ��ġ�� �̵����� �ֱ� ������ ���� �������� �ľ��ϰ� �ٷ� �ذ����־�� �Ѵ�.)
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos = renderer::mainCamera->CalculatePosition(pos);  //������Ʈ�� ��ġ�� ī�޶��� ��ġ�� ����ؼ� ����

		if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Bmp) {
			//�� �Լ��� �̹����� Ư�� ���� �����ϰ� ������� ȭ�鿡 ������ִ� �Լ��̴�.
			//�̰� ���� �ǹ��̳� �ϸ� ��Ʈ���� ���� ���� ����. �׷��ϱ� �� �ڼ��� �����ϸ� ��Ʈ���� Ư�� ����� �̹������� �������� �Ǿ� �ִ� ���Ϸ� �̴� ���� ������ Ȯ���غ��� �� �ڼ��� �� �� �ִ�.
			//�ƹ�ư �׷��� ���ִ� �̹����� �߿��� �ϳ��� �̹����� �߶� ����� �ϰ� ������ �տ��� ���ߵ��� ��Ʈ���� ���� ���� ������ ��Ȯ�ϰ� ����� �̹����� �ڸ��� ���� �Ұ����Ͽ� ������ ���� �ȴ�.
			//�׷��� �Ǹ� �̹��� �ڿ� �ٸ� ����� �־� ������ �ϼ����� �־����� �������� �Ǵµ� �̸� �ذ��ϱ� ���ؼ� �ִ� ���� �ٷ� �� �Լ��̴�. �� �Լ��� ��Ʈ���� �߶��� �� Ư�� ���� ����ȭ���� �ֱ�
			//������ ������ ����ȭ���� ������ �̹��� ����� �����ϰ� ���ش�.
			//�ϴ� �� �Լ��� ù ��° ���ڴ� ����� ��ġ�� dc�̰� �� �� ��° ���ڴ� �̹����� ����� ��ġ�̰� �� �ټ� ��° ���ڴ� �̹����� �ʺ�� �����̰� ���� ��° ���ڴ� �̹����� �ڵ�(dc)�̴�.
			//�׸��� �ϰ� ���� ��° ���ڴ� ������ �̹����� ���� �����̰� ��ȩ �� ��° ���ڴ� ���� �̹������� ���� �������� �߶� �̹����� �ʺ�� �����̸� ������ ���ڴ� �����ϰ� �� ����(RGB)�̴�.
			//�� ������ �Ʒ� ��α׿��� �����ִ� ������ �״�� ���� ���̱⿡ �� ���� ���� �ڼ��� �˷��� �Ʒ� ��α� �ּҷ� �� ���� �ȴ�.
			//https://blog.naver.com/power2845/50147965306
			//�̹����� ��Ʈ���� ����ϴ� ���� Ȯ���ϱ� ���� ���� ��ü�� ���
			//���� ��Ʈ���� ������ ����Ÿ ��(RGB(255,0,255))�� ����. �ֳ��ϸ�, �� ���� ���ҽ� �̹��� ��ü�� ������ Ȯ���� ���� ���� �����̴�.(�Ƹ� ������� Ȯ���� ���� ���� ���̴�.)
			TransparentBlt(hdc, pos.x, pos.y, mTexture->GetWidth(), mTexture->GetHeight(), mTexture->GetHdc(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight(), RGB(255, 0, 255));

			//��Ʈ���� �ڸ��� ����� ���߿� �߰����ֽ� ����
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