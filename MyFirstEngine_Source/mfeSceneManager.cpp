#include "mfeSceneManager.h"

namespace mfe {
	//static선언한 변수는 이렇게 클래스 외부에서 한 번 초기화하지 않으면 오류가 발생하게 되니 주의해야 한다.
	std::map<const std::wstring, Scene*> SceneManager::mScene = {};
	Scene* SceneManager::mActiveScene = nullptr;

	void SceneManager::Initialize()
	{
		
	}

	void SceneManager::Update()
	{
		mActiveScene->Update();
	}

	void SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}

	void SceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}
}