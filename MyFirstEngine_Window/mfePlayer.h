#pragma once
#include "..//MyFirstEngine_Source/mfeGameObject.h"

namespace mfe {
	class Player : public GameObject  //�÷��̾ ���� ������Ʈ�̱� ������ ���� ������Ʈ�� ��ӹ޴´�.
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
