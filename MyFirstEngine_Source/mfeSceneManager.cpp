#include "mfeSceneManager.h"

namespace mfe {
	//static������ ������ �̷��� Ŭ���� �ܺο��� �� �� �ʱ�ȭ���� ������ ������ �߻��ϰ� �Ǵ� �����ؾ� �Ѵ�.
	std::map<const std::wstring, Scene*> SceneManager::mScene = {};
	Scene* SceneManager::mActiveScene = nullptr;

	void SceneManager::Initialize() {

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

	Scene* SceneManager::LoadScene(const std::wstring& name) {
		if (mActiveScene) {  //���� ���� nullptr�� ��쿡�� �۵��ϸ� �� �Ǳ⿡ �̸� �˻�
			mActiveScene->OnExit();  //�� ��ȯ �� ���� ���� �ʿ��� ������ �ϴ� �Լ� ȣ��(���� ���� �Լ�)
		}

		//map�� Ȱ���� �� �ְ� ������ �Լ� find�� Ű ��(Scene�� �̸�)�� �־��ָ� �ش�Ǵ� map�� �ּ� ���� ��ȯ�ϴ� �Լ��̴�.
		std::map<std::wstring, Scene*>::iterator iter = mScene.find(name);  //��ȯ�� map�� �ּҸ� �����Ϳ� ����

		if (iter == mScene.end()) {  //end�� �� ������ ��� �ڿ� �ִ� �޸� ĭ�� �ǹ��Ѵ�. ���� �����Ͱ� �ִ� ���� �ƴϰ� �� ���������� �˷��ֱ� ���� �Ҵ�� �����̴�.
			return nullptr;
		}

		mActiveScene = iter->second;  //first = Ű, second = ���� ������ �� �ǹ�(��, ���� �����Ѵٴ� �ǹ�)

		mActiveScene->OnEnter();  //���� �ٲ�鼭 �ʿ��� ������ �ϴ� �Լ� ȣ��(��ȯ�� ���� �Լ�)

		return iter->second;
	}
}