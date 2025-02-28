#pragma once
#include "..\\MyFirstEngine_Source\\mfeScript.h"

namespace mfe {
	//씬처럼 스크립트도 상속받아서 추가해서 써야 한다.
	class PlayerScript : public Script
	{
	public:
		PlayerScript();

		//당연하게도 상속을 받았으니 재정의할 함수가 있으면 가져와서 재정의
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		~PlayerScript();

	private:

	};
}
