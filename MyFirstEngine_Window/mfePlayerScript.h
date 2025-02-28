#pragma once
#include "..\\MyFirstEngine_Source\\mfeScript.h"

namespace mfe {
	//��ó�� ��ũ��Ʈ�� ��ӹ޾Ƽ� �߰��ؼ� ��� �Ѵ�.
	class PlayerScript : public Script
	{
	public:
		PlayerScript();

		//�翬�ϰԵ� ����� �޾����� �������� �Լ��� ������ �����ͼ� ������
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		~PlayerScript();

	private:

	};
}
