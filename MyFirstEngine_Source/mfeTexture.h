#pragma once
#include "mfeResource.h"

namespace mfe::graphics {  //�׷��Ƚ� ���õ� �͵��� ������ ���ӽ����̽� �� ���ӽ����̽�(���� �� ���ұ��� �°� �ɰ� ���� ���� �� ū �ǹ̰� �ִ� ���� �ƴϴ�.)
	//�׷��� �̷��� ���ұ����� ��Ƴ����� ������ ���� �ִ� ������ �˱� ���� ������ �ǰ� �������� ���� �Ǵ� ������ �͵� ���� ����̴�.
	//�׸��� �̷��� �츮�� ����� Ŭ���� �ܿ��� �̹� WinAPi�� C++�� ������ ������ �̸��� �͵��� ���� ���� ������ �̰͵��� �����ϱ� ���ؼ� ����ϴ� �͵� �ִ�.
	class Texture : public Resource
	{
	public:
		enum class eTextureType {  //�ؽ��� ������ ���µ� ���� ������ �����Ƿ� �̹��� �ε带 �� �� �̸� �����ϱ� ���� enum class
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
		//(bmp - 24��Ʈ ����, png - 32��Ʈ ����)
		Gdiplus::Image* mImage;  //png������ �׸� ���� �̿� ���� Gdiplus�� �̹��� ��ü�� Ȱ��
		HBITMAP mBitmap;  //bmp������ �׸� ���� ��Ʈ�� Ȱ��
		HDC mHdc;  //���� ���۸� ���� �� ��Ʈ �� ����� ����� dc�� ���� �־��� ������ ���⼭�� ��Ʈ���� Ȱ���� �� ���� ����� dc�� �ʿ��ϴ�.

		//�̿� ���� ��Ʈ���� Ȱ���� ���� ���� �� ��ٷο� �κ��� �ִ�. �׷��� �̸� ������ ���� Gdiplus�̰� ��Ʈ�ʰ� dc�� �Բ� ���� ���� Gdi�� �Ѵ�.
		//��Ʈ�ʰ� dc�� ¦���� ������ �Բ� ���Ǿ�� �Ѵ�.

		UINT mWidth;
		UINT mHeight;
	};
}