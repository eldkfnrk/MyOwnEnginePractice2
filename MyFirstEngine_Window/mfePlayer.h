#pragma once
#include "..//MyFirstEngine_Source/mfeGameObject.h"

namespace mfe {
	class Player : public GameObject  //플레이어도 게임 오브젝트이기 때문에 게임 오브젝트를 상속받는다.
	{
	private:

	public:
		Player();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
		
		~Player();
	};
}
