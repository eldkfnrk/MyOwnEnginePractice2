#include "mfeLayer.h"

namespace mfe {
	Layer::Layer() : mGameObjects{} {
		
	}

	void Layer::Initialize()
	{
		for (GameObject* gameObj : mGameObjects) {
			if (gameObj == nullptr)
				continue;
			gameObj->Initialize();
		}
	}

	void Layer::Update()
	{
		//C++에 있는 범위 기반 for문
		for (GameObject* gameObj : mGameObjects) {
			if (gameObj == nullptr)
				continue;
			gameObj->Update();
		}
	}

	void Layer::LateUpdate()
	{
		for (GameObject* gameObj : mGameObjects) {
			if (gameObj == nullptr)
				continue;
			gameObj->LateUpdate();
		}
	}

	void Layer::Render(HDC hdc)
	{
		for (GameObject* gameObj : mGameObjects) {
			if (gameObj == nullptr)
				continue;
			gameObj->Render(hdc);
		}
	}

	void Layer::AddGameObject(GameObject* gameObject)  
	{
		//게임 오브젝트를 추가할 때 nullptr이 들어가면 문제가 발생한다.
		//왜냐하면, nullptr은 아무것도 없는 것인데 이것이 들어있는 벡터를 for문으로 돌리면 아무것도 없는 것이 함수에 접근하는 것은 당연히 불가능하니 오류가 생기게 된다.
		//그렇기에 nullptr이 들어가는 것을 방지하여야 한다.
		if (gameObject == nullptr) 
			return;
		
		mGameObjects.push_back(gameObject);
	}

	Layer::~Layer() {

	}
}