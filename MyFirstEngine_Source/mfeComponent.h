#pragma once
#include "mfeEntity.h"

namespace mfe {
	class GameObject;  //전방 선언이라는 문법을 사용
	//전방 선언을 한 이유는 게임 오브젝트가 이미 컴포넌트를 참조하고 있기 때문에 컴포넌트가 게임 오브젝트를 참조하게 되면 순환 참조가 되어 빌드가 불가능해진다.
	//순환 참조는 참조하는 대상이 서로 물려 있어 무한 루프처럼 서로 참조를 계속하기 때문에 빌드가 불가능하게 된다.
	//그래서 필요한 것이 전방 선언인데 클래스 내에서 해당 클래스의 포인터를 사용할 때 미리 해당 클래스가 필요하다는 것을 알려주기 위한 문법이다.
	//그렇게 하여 전방 선언한 클래스의 포인터를 #include로 참조하지 않아도 사용할 수 있게 되는 것이다.(단, 포인터형만 사용 가능으로 일반 클래스형은 사용 불가능)

	class Component : public Entity
	{
	private:
		GameObject* mOwner;  //컴포넌트들끼리 다른 컴포넌트를 가져와야 할 수도 있기 때문에 컴포넌트들은 항상 자신의 게임 오브젝트 형을 들고 있어주어야 한다.

	public:
		Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		//게임 오브젝트를 직접 접근이 아닌 간접 접근으로 사용하기 위해 Getter Setter를 사용
		void SetOwner(GameObject* owner) { mOwner = owner; }
		GameObject* GetOwner() { return mOwner; }

		~Component();
	};
}
