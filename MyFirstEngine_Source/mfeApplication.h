#pragma once
#include "CommonInclude.h"
//#include "mfeGameObject.h"
//#include "mfeScene.h"

namespace mfe {
	//�������� ���õ� �۾��� �ϴ� ���� ����
	class Application
	{
	private:
		HWND mHwnd;
		HDC mHdc;
		
		HDC mBackHdc;
		HBITMAP mBackBitmap;

		//ȭ�� ũ��(�ػ�)
		UINT mWidth; 
		UINT mHeight;  
		
		//GameObject player;

		//���� ������Ʈ�� ���� ���� �Ҵ�
		//GameObject* pPlayer;

		//���� ���� ���� ������Ʈ�� �߰��� �� ���� ������ �߰��� �ϰ� �Ǹ� �������ְ� �Ҵ����ְ� ������Ʈ �����ִ� ���� ��� �ݺ����־�� �Ѵ�.
		//�׷��� �ǰ� ���ŷο �̷��� ���� ���� �Ʒ��� ���� vector�� ����Ͽ� ������� ����ϸ� ���ŷο��� �پ��� �ȴ�.
		//�׷��� �̰͵��� ��ġ�� ���� ���ø����̼��� �ƴ϶� ���̰� �� ������ ������Ʈ���� ���ε��� �����ϰ� �� ���̱⿡ ������Ʈ ���� �ڵ���� ���ø����̼ǿ��� ���� �����ϴ� Ŭ������ �̵���Ų��.
		//std::vector<GameObject*> mGameObjects;

		//��� ������ ���ø����̼ǿ��� �����ϱ� ������ ���� ������ ������� ���͸� ����
		//std::vector<Scene*> mScenes;

		void clearRenderTarget();
		void copyRenderTarget(HDC source, HDC dest);
		void adjustWindowRect(HWND hwnd, UINT width, UINT height);
		void createBuffer(UINT width, UINT height);
		void initializeEtc();

	public:
		Application();

		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();
		void Update();
		void LateUpdate();
		void Render();

		~Application();
	};
}