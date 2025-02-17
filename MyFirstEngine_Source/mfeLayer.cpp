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
		//C++�� �ִ� ���� ��� for��
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
		//���� ������Ʈ�� �߰��� �� nullptr�� ���� ������ �߻��Ѵ�.
		//�ֳ��ϸ�, nullptr�� �ƹ��͵� ���� ���ε� �̰��� ����ִ� ���͸� for������ ������ �ƹ��͵� ���� ���� �Լ��� �����ϴ� ���� �翬�� �Ұ����ϴ� ������ ����� �ȴ�.
		//�׷��⿡ nullptr�� ���� ���� �����Ͽ��� �Ѵ�.
		if (gameObject == nullptr) 
			return;
		
		mGameObjects.push_back(gameObject);
	}

	Layer::~Layer() {

	}
}