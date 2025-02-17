#include "mfeSceneManager.h"

namespace mfe {
	//static������ ������ �̷��� Ŭ���� �ܺο��� �� �� �ʱ�ȭ���� ������ ������ �߻��ϰ� �Ǵ� �����ؾ� �Ѵ�.
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