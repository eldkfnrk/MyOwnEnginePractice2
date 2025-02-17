#pragma once
#include "mfeComponent.h"
#include "mfeGameObject.h"
#include "mfeLayer.h"
#include "mfeScene.h"
#include "mfeSceneManager.h"
#include "mfeTransform.h"

namespace mfe::object {
	//�÷��̾ ���, ���� ���� ������Ʈ���� ���� �� �ְ� �ϱ� ���� template���� �Լ��� �����.
	template <typename T>
	static T* Instantiate(mfe::enums::eLayerType type) {
		T* gameObject = new T();  //�⺻ ��ġ�� 0,0�� ��ġ�� ���� ���� ������Ʈ ����
		Scene* activeScene = SceneManager::GetActiveScene();  //���� ���� ȣ��
		Layer* layer = activeScene->GetLayer(type);  //������Ʈ�� ��ġ�� ���̾� ȣ��
		layer->AddGameObject(gameObject);

		return gameObject;  //�Լ��� ȣ���� �� ������Ʈ�� ���� ������ �� ������ �������ش�.
	}

	template <typename T>
	static T* Instantiate(mfe::enums::eLayerType type, math::Vector2 position) {  //�Լ� �����ε�(�����ϰ��� ��ġ ��ǥ�� �޴� �Ű����� �߰�)
		//math::Vector2�� 0,0�̶�� �⺻ ���� �־ ���� �Լ��� 0, 0�� ��ġ�� �Ǵµ� ���⼭�� ��ġ ������ �޾� �°� ��ġ
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		//�Ʒ� �ڵ带 �� �ٷ� ���� �� ������ �Ʒ��� ���� �����°� ���� �� ���� �ڵ尡 �ȴ�.
		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(position);

		return gameObject;
	}
}