#pragma once
#include "mfeEntity.h"

namespace mfe {
	class GameObject;  //���� �����̶�� ������ ���
	//���� ������ �� ������ ���� ������Ʈ�� �̹� ������Ʈ�� �����ϰ� �ֱ� ������ ������Ʈ�� ���� ������Ʈ�� �����ϰ� �Ǹ� ��ȯ ������ �Ǿ� ���尡 �Ұ���������.
	//��ȯ ������ �����ϴ� ����� ���� ���� �־� ���� ����ó�� ���� ������ ����ϱ� ������ ���尡 �Ұ����ϰ� �ȴ�.
	//�׷��� �ʿ��� ���� ���� �����ε� Ŭ���� ������ �ش� Ŭ������ �����͸� ����� �� �̸� �ش� Ŭ������ �ʿ��ϴٴ� ���� �˷��ֱ� ���� �����̴�.
	//�׷��� �Ͽ� ���� ������ Ŭ������ �����͸� #include�� �������� �ʾƵ� ����� �� �ְ� �Ǵ� ���̴�.(��, ���������� ��� �������� �Ϲ� Ŭ�������� ��� �Ұ���)

	class Component : public Entity
	{
	private:
		GameObject* mOwner;  //������Ʈ�鳢�� �ٸ� ������Ʈ�� �����;� �� ���� �ֱ� ������ ������Ʈ���� �׻� �ڽ��� ���� ������Ʈ ���� ��� �־��־�� �Ѵ�.

	public:
		Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		//���� ������Ʈ�� ���� ������ �ƴ� ���� �������� ����ϱ� ���� Getter Setter�� ���
		void SetOwner(GameObject* owner) { mOwner = owner; }
		GameObject* GetOwner() { return mOwner; }

		~Component();
	};
}
