#pragma once
#include "mfeEntity.h"
#include "CommonInclude.h"
#include "mfeGameObject.h"

namespace mfe {
	//2d 게임을 만들 때에는 배경과 플레이어, npc, 몬스터 등등의 오브젝트들이 있을 수 있고 이 오브젝트들은 한 화면에 그려진다.
	//그러면 게임을 플레이하기 위해서는 플레이어와 몬스터, npc는 배경 위에 있어야 이들을 보고 플레이를 할 수 있는데 지금과 같이 C++로
	//게임을 만들게 되면 오브젝트 호출 순서로 화면에 그려지게 되고 그러면 실수로 플레이어가 배경 아래에 가거나 몬스터가 배경 아래로 가서 정상적인
	//게임 플레이가 불가능하게 되는 불상사가 발생할 수 있다. 그러면 오브젝트 호출을 순서대로 잘 배치하여야 하는데 이는 실제 게임 개발 환경에서는
	//신경쓰기 어려울 수 있다. 그렇기에 이 문제를 해결하기 위해서 레이어라는 것이 필요하다.
	//레이어란 층이라는 뜻을 가지고 있는데 말 그대로 오브젝트들을 층을 나누고 위나 아래에 배치할 것을 알맞게 정하는 것이다.
	//이러면 오브젝트의 호출 순서를 신경쓰지 않고 알맞는 레이어에 배치만 하면 되기에 레이어가 필요한 것이다.
	class Layer : public Entity
	{
	private:
		//int mLayer;
		//eLayerType mType;  //위의 int형으로 레이어를 사용해도 되지만 그것보단 이름이 있어 레이어를 조금 더 쉽게 파악 가능한 enum을 사용(아직 구현 못한 지금은 필요x)
		std::vector<GameObject*> mGameObjects;  //기존에 Scene클래스에서 관리하던 게임 오브젝트를 레이어에서 관리
		//레이어가 오브젝트를 관리하는 이유는 레이어마다 있는 오브젝트들을 레이어가 가지고 있어야 하기 때문에 옮긴 것이다.

		//레이어에 저장된 오브젝트들을 보면 2차원 배열과 유사한 형태를 보인다.

	public:
		Layer();

		//오브젝트를 씬에서부터 가져왔으니 그 동안 씬에서 하던 동작을 레이어가 하게 된다.
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* gameObject);

		~Layer();
	};
}
