#include "mfeSpriteRenderer.h"
#include "mfeGameObject.h"
#include "mfeTransform.h"

namespace mfe {
	void SpriteRenderer::ImageLoad(const std::wstring& path)
	{
		mImage = Gdiplus::Image::FromFile(path.c_str());
		mWidth = mImage->GetWidth();
		mHeight = mImage->GetHeight();
	}

	SpriteRenderer::SpriteRenderer() : mImage(nullptr), mWidth(0), mHeight(0)
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
		//HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
		//HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		//HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		//HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

		//SelectObject(hdc, oldPen);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		//Rectangle(hdc, tr->GetX(), tr->GetY(), 100 + tr->GetX(), 100 + tr->GetY());  //길이가 100인 정사각형 형성

		//SelectObject(hdc, oldBrush);
		//DeleteObject(blueBrush);
		//DeleteObject(redPen);

		Gdiplus::Graphics graphics(hdc);
		graphics.DrawImage(mImage, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));
	}

	SpriteRenderer::~SpriteRenderer()
	{
	}
}