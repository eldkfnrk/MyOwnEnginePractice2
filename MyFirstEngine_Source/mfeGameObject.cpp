#include "mfeGameObject.h"
#include "mfeInput.h"
#include "mfeTime.h"
#include "mfeTransform.h"

namespace mfe {
	GameObject::GameObject(){
		mComponents.resize((UINT)enums::eComponentType::End);  //벡터의 크기 재할당(이 벡터의 크기를 End로 한 이유는 End는 enum의 마지막이니 모든 컴포넌트를 수용할 수 있는 최대 크기이기 때문)

		//게임 오브젝트를 만들면 디폴트로 transform은 추가되도록 변경
		//위치 데이터는 항상 쓰기 때문에 반드시 필요해서 이렇게 디폴트로 추가되도록 만드는 것이다.
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

	void GameObject::initializeTransform() {  //한 줄만 있어도 함수에 묶어주는 습관을 갖는 것이 좋다.
		AddComponent<Transform>();
	}
}