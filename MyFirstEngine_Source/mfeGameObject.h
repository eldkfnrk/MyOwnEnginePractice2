#pragma once
#include "CommonInclude.h"
#include "mfeComponent.h"

namespace mfe {
	//���� ������Ʈ ���� �۾��ϴ� ���� ����
	//���� Ŭ������ ���� �������� ������Ʈ ������ �����ϱ� ���� Ŭ������ ���� ����
	class GameObject
	{
	public:
		GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);  

		template <typename T>
		T* AddComponent() {
			T* comp = new T();
			comp->Initialize();
			comp->SetOwner(this);  //this�� ��ü �ڽ��� �ǹ��Ѵ�. ���⼭�� �� Ŭ������ ��ü�� �� ���̴�.
			
			mComponents[(UINT)comp->GetType()] = comp;  //������Ʈ Ÿ�Կ� �´� ������ �ε����� ������Ʈ�� �ְڴٴ� �ǹ�
			//mComponents.push_back(comp);  //������Ʈ�� ������Ʈ�� ������ �迭�� �߰�(���� ������ �߰��Ǹ� �̿� ���� push_back�� ���� ����ϰ� �ȴ�.)

			return comp;
		}

		template <typename T>
		T* GetComponent() {
			T* component = nullptr;  //�� ��ü�� ����
			for (Component* comp : mComponents) {
				component = dynamic_cast<T*>(comp);  //dynamic_cast�� ���� ���� �����ڸ� �θ� Ŭ������ ��ü�� �ڽ� Ŭ������ ��ü �����ͷ� ����Ű�� ������ ������ �� ��ȯ�� �ش�
				if (component)  //������Ʈ�� ����Ű�� ���� ���� ��� �ݺ��� Ż��
					break;
			}
			
			return component;
		}

		~GameObject();	

	private:
		std::vector<Component*> mComponents;  //����� ������Ʈ���� ������ �迭
		
		void initializeTransform();
	};
}