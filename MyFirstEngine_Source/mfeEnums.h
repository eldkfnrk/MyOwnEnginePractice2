#pragma once

//���̾�� ������ enum�� �����ϴ� ��� ����
namespace mfe {
	enum class eLayerType{
		None,
		BackGround,
		//�ʿ��Ѹ�ŭ ����(Tree�� Character���� �͵�)
		Player,
		Max=16,  //�ִ� 16���� ���(���̾ ��û���� ������ ���� ���̱⿡)
		//�翬�ϰ� �ʿ信 ���� �ִ� ũ�⸦ �����ؼ� ����ϸ� �ȴ�.
	};
}