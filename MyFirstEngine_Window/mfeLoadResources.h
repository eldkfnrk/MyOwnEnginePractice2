#pragma once

#include "..//MyFirstEngine_Source//mfeResources.h"  //�ٸ� ������Ʈ�� �ְ� �����ϰ� �ִ� ���°� �ƴ϶� ��Ȯ�� ������ ��ġ�� �����ؾ� �Ѵ�.
#include "..//MyFirstEngine_Source//mfeTexture.h"

namespace mfe {
	void LoadResources() {
		//�ش� ����� ���ҽ��� �ε�(ù ��° ���ڴ� �ҷ����� ���ҽ����� ���� �̸�)
		Resources::Load<graphics::Texture>(L"BG", L"D:\\GameEnginePractice\\MyOwnEnginePractice-master\\Resources\\CloudOcean.png");
	}
}