#pragma once
#include "mfeComponent.h"

//게임 오브젝트의 위치 정보를 관장하는 컴포넌트
namespace mfe {
	//struct pos {  //게임 오브젝트의 위치 정보를 가지는 구조체 -> 새로 지정한 구조체가 있기 때문에 이 구조체는 더 이상 필요하지 않아서 삭제
	//	int mX;
	//	int mY;
	//};

	using namespace math;

	class Transform : public Component
	{
	private:
		Vector2 mPosition;

	public:
		Transform();
		
		//부모 클래스의 가상 함수를 오버라이드 하겠다 명시
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		//위치 정보를 설정하고 외부에서 사용하기 위한 Getter Setter
		void SetPos(Vector2 pos) {
			mPosition.x = pos.x;
			mPosition.y = pos.y;
		}
		
		Vector2 GetPosition() {
			return mPosition;
		}

		//int GetX() { return mX; }
		//int GetY() { return mY; }

		~Transform();
	};
}
