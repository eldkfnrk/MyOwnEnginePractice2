#pragma once
#include "mfeComponent.h"
#include "CommonInclude.h"

namespace mfe {
	//스크립트 컴포넌트
	//스크립트는 게임 플레이에 필요한 로직을 실행시켜주는 컴포넌트이다.(캐릭터의 움직임이나 몬스터 AI등의 로직)
	//스크립트는 다른 컴포넌트들보다 먼저 업데이트가 진행되어야 하는데 그 이유는 로직에 따른 움직임을 적용시키기 위해서는 스크립트가 진행되고 위치 변화나 화면 출력이 진행되어야
	//문제없이 동작을 하기 때문이다. 만약, 화면 출력이 스크립트보다 먼저 되면 화면 출력은 x=1에 되고 있는데 이미 데이터는 x=2로 바뀌어서 오차가 발생한다.
	//이 때문에 이번에 만들어보는 엔진에서는 이렇게 하지만 상황에 알맞게 업데이트 순서를 조정해야 원하는 결과를 도출해낼 수 있으니 생각을 많이 해보고 결정해야 한다.
	class Script : public Component
	{
	public: 
		Script();

		//상속받는 Component 클래스의 가상 함수를 재정의
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		~Script();

	private:

	};
}