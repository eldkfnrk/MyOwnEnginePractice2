#include "mfeApplication.h"
#include "mfeInput.h"
#include "mfeTime.h"
#include "mfeSceneManager.h"  //�� ��� ���Ͽ� �ʿ��� ��� ���� #include�Ǿ� �ֱ� ������ �̰� �ϳ��� #include�ϸ� �ȴ�.
//���� ���� ������Ʈ�� ���Ŵ����� ���� �����ϱ� ������ ���Ŵ����� #include�ϸ� �Ǵ� ���̴�.

namespace mfe {
	Application::Application()
		:mHwnd(nullptr), mHdc(nullptr), mWidth(0), mHeight(0), mBackHdc(NULL), mBackBitmap(NULL) {

	}

	void Application::Initialize(HWND hwnd, UINT width, UINT height) {
		adjustWindowRect(hwnd, width, height);
		createBuffer(width, height);
		initializeEtc();

		//pPlayer = new GameObject();

		//������Ʈ�� ������ ������ ���̱⿡ ���� �����ϴ� Ŭ������ �̵��Ͽ��� �Ѵ�.
		//for (size_t i = 0; i < 100; i++) {
		//	GameObject* gameObj = new GameObject();

		//	gameObj->SetPosition(rand() % 1600, rand() % 900);  //�۾� ������ ũ�Ⱑ 1600, 900�̱� ������ �̸� ����� �ʰ� ����� ���Ͽ� ������ ������ ���־���.
		//	mGameObjects.push_back(gameObj);  //������ ��� �߰�
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

		//������Ʈ�� ������ ������ ���̱⿡ ���� �����ϴ� Ŭ������ �̵��Ͽ��� �Ѵ�.
		//for (size_t i = 0; i < mGameObjects.size(); i++) {
		//	//(*mGameObjects[i]).Update();  //�� �ٸ� ����� �����ϴ� ����̴�.(�� ���α׷������� ū ���̰� �����Ƿ� �ƹ��ų� ����ص� �ȴ�.)
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

		//������Ʈ�� ������ ������ ���̱⿡ ���� �����ϴ� Ŭ������ �̵��Ͽ��� �Ѵ�.
		//for (size_t i = 0; i < mGameObjects.size(); i++) {
		//	mGameObjects[i]->Render(mBackHdc);
		//}

		SceneManager::Render(mBackHdc);

		copyRenderTarget(mBackHdc, mHdc);
	}

	void Application::clearRenderTarget() {  //���������� �׷����� ȭ���� ����� �Լ�(���� �� ����ϰ� �ϱ� ���� ȭ�麸�� ũ�� �ؼ� �׵θ��� �� ���̰� ���ִ� �۾��� �Բ� ����)
		//���� �� ũ��� ������ ����� �Ǹ� �׵θ��� ���̰� �Ǵµ� �׷��� �����ϴ� ũ�⸦ ���ݸ� ����
		//Rectangle(mBackHdc, 0, 0, mWidth, mHeight);
		Rectangle(mBackHdc, -1, -1, mWidth + 1, mHeight + 1);  //�̷��� �����¿츦 �� ĭ���� �÷��� ȭ�鿡 ���̴� �׵θ��� �� ���̰� ����
	}

	void Application::copyRenderTarget(HDC source, HDC dest) {  //source ���� DC�� �����ؼ� dest ���� DC���� ����ϴ� �Լ�
		BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
	}

	void Application::adjustWindowRect(HWND hwnd, UINT width, UINT height) {  //���� �۾� ������ �����ϴ� ���� ������� �Լ�
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0, 0, width, height };  //���� �۾� ������ �˱� ���� RECT��� �ڷ� ������ ���

		//���� ������ ũ��, ������ ����, �޴� ���� ������ ���ڸ� �޴´�.
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);  //�� ���α׷��� ����� ������ â�� �۾� ���� ũ�⸦ �����ִ� �Լ�

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		//������ ��ġ ������ ���� ����
		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);
	}

	void Application::createBuffer(UINT width, UINT height) {  //����۸� ����� ������ ������� �Լ�
		//������ �ػ󵵿� �´� �����(��ȭ��) ����
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		//����۸� ����ų DC����
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