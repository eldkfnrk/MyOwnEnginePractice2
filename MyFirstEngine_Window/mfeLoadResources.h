#pragma once

#include "..//MyFirstEngine_Source//mfeResources.h"  //�ٸ� ������Ʈ�� �ְ� �����ϰ� �ִ� ���°� �ƴ϶� ��Ȯ�� ������ ��ġ�� �����ؾ� �Ѵ�.
#include "..//MyFirstEngine_Source//mfeTexture.h"

namespace mfe {
	void LoadResources() {
		//�ش� ����� ���ҽ��� �ε�(ù ��° ���ڴ� �ҷ����� ���ҽ����� ���� �̸�)
		//Resources::Load<graphics::Texture>(L"BG", L"..\\Resources\\CloudOcean.png");
		Resources::Load<graphics::Texture>(L"Map", L"..\\Resources\\img\\map\\map_pure.png");
		Resources::Load<graphics::Texture>(L"PackMan0", L"..\\Resources\\img\\pacman\\0.png");
		Resources::Load<graphics::Texture>(L"PackMan1", L"..\\Resources\\img\\pacman\\1.png");
		Resources::Load<graphics::Texture>(L"PackMan2", L"..\\Resources\\img\\pacman\\2.png");
	}
}

//�̹��� �߰��� ����

//1. ī�޶�
//2. ũ�� ����
//3. ��ũ��Ʈ