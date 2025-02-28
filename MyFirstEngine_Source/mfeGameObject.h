#pragma once
#include "CommonInclude.h"
#include "mfeComponent.h"

namespace mfe {
	//게임 오브젝트 관련 작업하는 역할 수행
	//기존 클래스의 계층 구조에서 컴포넌트 구조로 변경하기 위해 클래스를 새로 설계
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
			comp->SetOwner(this);  //this는 객체 자신을 의미한다. 여기서는 이 클래스의 객체가 될 것이다.
			
			mComponents[(UINT)comp->GetType()] = comp;  //컴포넌트 타입에 맞는 숫자의 인덱스에 컴포넌트를 넣겠다는 의미
			//mComponents.push_back(comp);  //컴포넌트를 컴포넌트를 관리할 배열에 추가(위의 구문이 추가되면 이와 같이 push_back의 일을 대신하게 된다.)

			return comp;
		}

		template <typename T>
		T* GetComponent() {
			T* component = nullptr;  //빈 객체를 생성
			for (Component* comp : mComponents) {
				component = dynamic_cast<T*>(comp);  //dynamic_cast는 조금 쉽게 말하자면 부모 클래스의 객체를 자식 클래스의 객체 포인터로 가리키는 것으로 강제적 형 변환에 해당
				if (component)  //컴포넌트가 가리키는 값이 없는 경우 반복문 탈출
					break;
			}
			
			return component;
		}

		~GameObject();	

	private:
		std::vector<Component*> mComponents;  //사용할 컴포넌트들을 관리할 배열
		
		void initializeTransform();
	};
}