#pragma once
#include "..//MyFirstEngine_Source//mfeScene.h"

namespace mfe {
	class TitleScene : public Scene
	{
	private:

	public:
		TitleScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

		~TitleScene();
	};
}

