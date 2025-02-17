#include "mfeApplication.h"
#include "mfeInput.h"
#include "mfeTime.h"
#include "mfeSceneManager.h"  //이 헤더 파일에 필요한 모든 것이 #include되어 있기 때문에 이거 하나만 #include하면 된다.
//씬은 게임 오브젝트를 씬매니저는 씬을 관리하기 때문에 씬매니저만 #include하면 되는 것이다.

namespace mfe {
	Application::Application()
		:mHwnd(nullptr), mHdc(nullptr), mWidth(0), mHeight(0), mBackHdc(NULL), mBackBitmap(NULL) {

	}

	void Application::Initialize(HWND hwnd, UINT width, UINT height) {
		adjustWindowRect(hwnd, width, height);
		createBuffer(width, height);
		initializeEtc();

		//pPlayer = new GameObject();

		//오브젝트는 씬에서 관리할 것이기에 씬을 관리하는 클래스로 이동하여야 한다.
		//for (size_t i = 0; i < 100; i++) {
		//	GameObject* gameObj = new GameObject();

		//	gameObj->SetPosition(rand() % 1600, rand() % 900);  //작업 영역의 크기가 1600, 900이기 때문에 이를 벗어나지 않고 만들기 위하여 나머지 연산을 해주었다.
		//	mGameObjects.push_back(gameObj);  //벡터의 요소 추가
		//}

		SceneManager::Initialize();
	}

	void Application::Run() {
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update() {
		Input::Update();
		Time::Update();

		//player.Update();
		//pPlayer->Update();

		//오브젝트는 씬에서 관리할 것이기에 씬을 관리하는 클래스로 이동하여야 한다.
		//for (size_t i = 0; i < mGameObjects.size(); i++) {
		//	//(*mGameObjects[i]).Update();  //또 다른 멤버에 접근하는 방법이다.(이 프로그램에서는 큰 차이가 없으므로 아무거나 사용해도 된다.)
		//	mGameObjects[i]->Update();
		//}
		SceneManager::Update();
	}

	void Application::LateUpdate() {
		SceneManager::LateUpdate();
	}

	void Application::Render() {
		clearRenderTarget();

		Time::Render(mBackHdc);
		//player.Render(mBackHdc);

		//오브젝트는 씬에서 관리할 것이기에 씬을 관리하는 클래스로 이동하여야 한다.
		//for (size_t i = 0; i < mGameObjects.size(); i++) {
		//	mGameObjects[i]->Render(mBackHdc);
		//}

		SceneManager::Render(mBackHdc);

		copyRenderTarget(mBackHdc, mHdc);
	}

	void Application::clearRenderTarget() {  //최종적으로 그려지는 화면을 만드는 함수(조금 더 깔끔하게 하기 위해 화면보다 크게 해서 테두리를 안 보이게 해주는 작업도 함께 진행)
		//지금 이 크기로 도형을 만들게 되면 테두리가 보이게 되는데 그러면 불편하니 크기를 조금만 변경
		//Rectangle(mBackHdc, 0, 0, mWidth, mHeight);
		Rectangle(mBackHdc, -1, -1, mWidth + 1, mHeight + 1);  //이렇게 상하좌우를 한 칸씩만 늘려서 화면에 보이는 테두리가 안 보이게 변경
	}

	void Application::copyRenderTarget(HDC source, HDC dest) {  //source 인자 DC를 복사해서 dest 인자 DC에서 출력하는 함수
		BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
	}

	void Application::adjustWindowRect(HWND hwnd, UINT width, UINT height) {  //실제 작업 영역을 세팅하는 것을 묶어놓은 함수
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0, 0, width, height };  //실제 작업 영역을 알기 위해 RECT라는 자료 구조를 사용

		//현재 윈도우 크기, 윈도우 형태, 메뉴 여부 순으로 인자를 받는다.
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);  //이 프로그램이 만드는 윈도우 창의 작업 영역 크기를 정해주는 함수

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		//윈도우 위치 조정을 위한 세팅
		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);
	}

	void Application::createBuffer(UINT width, UINT height) {  //백버퍼를 만드는 과정을 묶어놓은 함수
		//윈도우 해상도에 맞는 백버퍼(도화지) 생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		//백버퍼를 가르킬 DC생성
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);
	}

	void Application::initializeEtc() {
		Input::Initialize();
		Time::Initialize();
	}

	Application::~Application() {

	}
}