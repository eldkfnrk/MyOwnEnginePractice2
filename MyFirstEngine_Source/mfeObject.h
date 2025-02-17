#pragma once
#include "mfeComponent.h"
#include "mfeGameObject.h"
#include "mfeLayer.h"
#include "mfeScene.h"
#include "mfeSceneManager.h"
#include "mfeTransform.h"

namespace mfe::object {
	//플레이어나 배경, 몬스터 등의 오브젝트들을 만들 수 있게 하기 위해 template으로 함수를 만든다.
	template <typename T>
	static T* Instantiate(mfe::enums::eLayerType type) {
		T* gameObject = new T();  //기본 위치인 0,0의 위치를 가진 게임 오브젝트 생성
		Scene* activeScene = SceneManager::GetActiveScene();  //현재 씬을 호출
		Layer* layer = activeScene->GetLayer(type);  //오브젝트가 배치된 레이어 호출
		layer->AddGameObject(gameObject);

		return gameObject;  //함수를 호출할 때 오브젝트를 따로 저장할 수 있으니 리턴해준다.
	}

	template <typename T>
	static T* Instantiate(mfe::enums::eLayerType type, math::Vector2 position) {  //함수 오버로딩(생성하고픈 위치 좌표를 받는 매개변수 추가)
		//math::Vector2는 0,0이라는 기본 값이 있어서 위의 함수는 0, 0에 배치가 되는데 여기서는 위치 정보를 받아 맞게 배치
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		//아래 코드를 한 줄로 줄일 수 있지만 아래와 같이 나누는게 조금 더 좋은 코드가 된다.
		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(position);

		return gameObject;
	}
}