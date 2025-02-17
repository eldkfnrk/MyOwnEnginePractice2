#include "mfeGameObject.h"
#include "mfeInput.h"
#include "mfeTime.h"

namespace mfe {
	GameObject::GameObject(){

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
}