#include "mfeGameObject.h"
#include "mfeInput.h"
#include "mfeTime.h"
#include "mfeTransform.h"

namespace mfe {
	GameObject::GameObject(){
		mComponents.resize((UINT)enums::eComponentType::End);  //������ ũ�� ���Ҵ�(�� ������ ũ�⸦ End�� �� ������ End�� enum�� �������̴� ��� ������Ʈ�� ������ �� �ִ� �ִ� ũ���̱� ����)

		//���� ������Ʈ�� ����� ����Ʈ�� transform�� �߰��ǵ��� ����
		//��ġ �����ʹ� �׻� ���� ������ �ݵ�� �ʿ��ؼ� �̷��� ����Ʈ�� �߰��ǵ��� ����� ���̴�.
		initializeTransform();
	}

	void GameObject::Initialize() {
		for (Component* comp : mComponents) {
			if (comp == nullptr) {
				continue;
			}

			comp->Initialize();
		}
	}

	void GameObject::Update() {
		for (Component* comp : mComponents) {
			if (comp == nullptr) {
				continue;
			}

			comp->Update();
		}
	}

	void GameObject::LateUpdate() {
		for (Component* comp : mComponents) {
			if (comp == nullptr) {
				continue;
			}

			comp->LateUpdate();
		}
	}

	void GameObject::Render(HDC hdc) {
		for (Component* comp : mComponents) {
			if (comp == nullptr) {
				continue;
			}

			comp->Render(hdc);
		}
	}

	GameObject::~GameObject() {
		for (Component* comp : mComponents) {
			if (comp == nullptr) {
				continue;
			}

			delete comp;
			comp = nullptr;
		}
	}

	void GameObject::initializeTransform() {  //�� �ٸ� �־ �Լ��� �����ִ� ������ ���� ���� ����.
		AddComponent<Transform>();
	}
}