#include "mfeSceneManager.h"

namespace mfe {
	//static선언한 변수는 이렇게 클래스 외부에서 한 번 초기화하지 않으면 오류가 발생하게 되니 주의해야 한다.
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
		if (mActiveScene) {  //현재 씬이 nullptr인 경우에는 작동하면 안 되기에 이를 검사
			mActiveScene->OnExit();  //씬 전환 시 기존 씬에 필요한 동작을 하는 함수 호출(기존 씬의 함수)
		}

		//map을 활용할 수 있게 구현된 함수 find는 키 값(Scene의 이름)을 넣어주면 해당되는 map의 주소 값을 반환하는 함수이다.
		std::map<std::wstring, Scene*>::iterator iter = mScene.find(name);  //반환된 map의 주소를 포인터에 저장

		if (iter == mScene.end()) {  //end는 맨 마지막 요소 뒤에 있는 메모리 칸을 의미한다. 실제 데이터가 있는 곳은 아니고 맨 마지막임을 알려주기 위해 할당된 공간이다.
			return nullptr;
		}

		mActiveScene = iter->second;  //first = 키, second = 실제 데이터 를 의미(즉, 씬을 대입한다는 의미)

		mActiveScene->OnEnter();  //씬이 바뀌면서 필요한 동작을 하는 함수 호출(전환된 씬의 함수)

		return iter->second;
	}
}