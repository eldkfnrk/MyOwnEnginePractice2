#pragma once
#include "mfeComponent.h"  
//#include "mfeGameObject.h"  

namespace mfe {
	using namespace mfe::math;
	//카메라 컴포넌트
	//카메라는 게임 플레이에 지대한 영향을 주는 컴포넌트이기 때문에 반드시 카메라를 담당하는 게임 오브젝트가 하나는 존재해야 한다.
	//2d 게임을 해보면 rpg라든지 플랫포머라든지 여러 장르의 게임이 플레이어 캐릭터가 있고 이 캐릭터의 움직임에 따라 화면이 이동하는 것을 알 수 있다.
	//그렇기에 카메라를 이동시키는 방식으로 구현을 하여야 한다.(물론 퍼즐 게임처럼 화면을 통째로 보여주는 경우처럼 이동을 안 하는 경우도 있지만 이 경우도 위치가 고정일 뿐 위치 정보는 가지고 있다.)
	//해당 엔진의 카메라는 한 오브젝트를 타겟으로 따라가는 카메라를 구현할 예정(다른 게임을 개발할 때 게임의 상황에 알맞게 위치나 이동을 생각하여 구현하면 된다.)
	class Camera : public Component
	{
	public:
		Vector2 CalculatePosition(Vector2 pos) {  //카메라의 좌표를 계산해 줄 함수(인자로 카메라 오브젝트의 위치 정보를 받는다.)
			return pos - mDistance;
		}

		Camera();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;


		~Camera();

	private:
		//std::vector<GameObject*> mGameObject;  //씬 내의 모든 오브젝트를 가지고 와서 이들을 이동시키는 방법으로 구현하려 했으나 문제가 생겨 카메라를 이동시키는 방향으로 전환

		class GameObject* mTarget;  //화면이 따라갈 타겟 오브젝트
		Vector2 mDistance;  //카메라가 이동한 거리
		Vector2 mResolution;  //화면 해상도
		Vector2 mLookPosition;  //카메라가 바라보는 화면 위치
	};
}