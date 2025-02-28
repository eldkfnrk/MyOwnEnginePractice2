#pragma once
#include "mfeComponent.h"  
//#include "mfeGameObject.h"  

namespace mfe {
	using namespace mfe::math;
	//ī�޶� ������Ʈ
	//ī�޶�� ���� �÷��̿� ������ ������ �ִ� ������Ʈ�̱� ������ �ݵ�� ī�޶� ����ϴ� ���� ������Ʈ�� �ϳ��� �����ؾ� �Ѵ�.
	//2d ������ �غ��� rpg����� �÷����Ӷ���� ���� �帣�� ������ �÷��̾� ĳ���Ͱ� �ְ� �� ĳ������ �����ӿ� ���� ȭ���� �̵��ϴ� ���� �� �� �ִ�.
	//�׷��⿡ ī�޶� �̵���Ű�� ������� ������ �Ͽ��� �Ѵ�.(���� ���� ����ó�� ȭ���� ��°�� �����ִ� ���ó�� �̵��� �� �ϴ� ��쵵 ������ �� ��쵵 ��ġ�� ������ �� ��ġ ������ ������ �ִ�.)
	//�ش� ������ ī�޶�� �� ������Ʈ�� Ÿ������ ���󰡴� ī�޶� ������ ����(�ٸ� ������ ������ �� ������ ��Ȳ�� �˸°� ��ġ�� �̵��� �����Ͽ� �����ϸ� �ȴ�.)
	class Camera : public Component
	{
	public:
		Vector2 CalculatePosition(Vector2 pos) {  //ī�޶��� ��ǥ�� ����� �� �Լ�(���ڷ� ī�޶� ������Ʈ�� ��ġ ������ �޴´�.)
			return pos - mDistance;
		}

		Camera();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;


		~Camera();

	private:
		//std::vector<GameObject*> mGameObject;  //�� ���� ��� ������Ʈ�� ������ �ͼ� �̵��� �̵���Ű�� ������� �����Ϸ� ������ ������ ���� ī�޶� �̵���Ű�� �������� ��ȯ

		class GameObject* mTarget;  //ȭ���� ���� Ÿ�� ������Ʈ
		Vector2 mDistance;  //ī�޶� �̵��� �Ÿ�
		Vector2 mResolution;  //ȭ�� �ػ�
		Vector2 mLookPosition;  //ī�޶� �ٶ󺸴� ȭ�� ��ġ
	};
}