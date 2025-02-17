#pragma once
#include "CommonInclude.h"
//#include "mfeGameObject.h"
//#include "mfeScene.h"

namespace mfe {
	//윈도우의 관련된 작업만 하는 역할 수행
	class Application
	{
	private:
		HWND mHwnd;
		HDC mHdc;
		
		HDC mBackHdc;
		HBITMAP mBackBitmap;

		//화면 크기(해상도)
		UINT mWidth; 
		UINT mHeight;  
		
		//GameObject player;

		//게임 오브젝트에 관한 동적 할당
		//GameObject* pPlayer;

		//위와 같이 게임 오브젝트를 추가할 때 저런 식으로 추가를 하게 되면 선언해주고 할당해주고 업데이트 시켜주는 것을 계속 반복해주어야 한다.
		//그러면 되게 번거로운데 이렇게 하지 말고 아래와 같이 vector를 사용하여 묶어놓고 사용하면 번거로움이 줄어들게 된다.
		//그러나 이것들이 위치할 곳은 어플리케이션이 아니라 씬이고 그 씬마다 오브젝트들을 따로따로 관리하게 될 것이기에 오브젝트 관련 코드들을 어플리케이션에서 씬을 관리하는 클래스로 이동시킨다.
		//std::vector<GameObject*> mGameObjects;

		//대신 씬들은 어플리케이션에서 동작하기 때문에 여러 씬들을 묶어놓을 벡터를 선언
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