#include "mfeGameObject.h"
#include "mfeInput.h"
#include "mfeTime.h"
#include "mfeTransform.h"

namespace mfe {
	GameObject::GameObject(){
		//���� ������Ʈ�� ����� ����Ʈ�� transform�� �߰��ǵ��� ����
		//��ġ �����ʹ� �׻� ���� ������ �ݵ�� �ʿ��ؼ� �̷��� ����Ʈ�� �߰��ǵ��� ����� ���̴�.
		initializeTransform();
	}

	void GameObject::Initialize() {
		for (Component* comp : mComponents) {
			comp->Initialize();
		}
	}

	void GameObject::Update() {
		for (Component* comp : mComponents) {
			comp->Update();
		}
	}

	void GameObject::LateUpdate() {
		for (Component* comp : mComponents) {
			comp->LateUpdate();
		}
	}

	void GameObject::Render(HDC hdc) {
		for (Component* comp : mComponents) {
			comp->Render(hdc);
		}
	}

	GameObject::~GameObject() {
		for (Component* comp : mComponents) {
			delete comp;
			comp = nullptr;
		}
	}

	void GameObject::initializeTransform() {  //�� �ٸ� �־ �Լ��� �����ִ� ������ ���� ���� ����.
		AddComponent<Transform>();
	}
}