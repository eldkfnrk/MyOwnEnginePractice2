#pragma once
#include "mfeComponent.h"

//���� ������Ʈ�� ��ġ ������ �����ϴ� ������Ʈ
namespace mfe {
	//struct pos {  //���� ������Ʈ�� ��ġ ������ ������ ����ü -> ���� ������ ����ü�� �ֱ� ������ �� ����ü�� �� �̻� �ʿ����� �ʾƼ� ����
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
		
		//�θ� Ŭ������ ���� �Լ��� �������̵� �ϰڴ� ���
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		//��ġ ������ �����ϰ� �ܺο��� ����ϱ� ���� Getter Setter
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
