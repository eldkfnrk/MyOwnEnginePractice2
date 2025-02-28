#pragma once
#include "..//MyFirstEngine_Source//mfeScene.h"

namespace mfe {
	class PlayScene : public Scene
	{
	private: 
		class Player* mPlayer;  //해당 씬의 플레이어(전방 선언)

	public:
		PlayScene();
 
		//부모 클래스의 가상 함수를 오버라이드한다는 것을 컴파일러에게 알려주기 위해 override를 써주어야 한다.
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

		~PlayScene();
	};
}