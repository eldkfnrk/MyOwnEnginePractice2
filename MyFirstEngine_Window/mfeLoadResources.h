#pragma once

#include "..//MyFirstEngine_Source//mfeResources.h"  //다른 프로젝트에 있고 참조하고 있는 상태가 아니라 정확한 파일의 위치를 기입해야 한다.
#include "..//MyFirstEngine_Source//mfeTexture.h"

namespace mfe {
	void LoadResources() {
		//해당 경로의 리소스를 로드(첫 번째 인자는 불러오는 리소스에게 붙일 이름)
		//Resources::Load<graphics::Texture>(L"BG", L"..\\Resources\\CloudOcean.png");
		Resources::Load<graphics::Texture>(L"Map", L"..\\Resources\\img\\map\\map_pure.png");
		Resources::Load<graphics::Texture>(L"PackMan0", L"..\\Resources\\img\\pacman\\0.png");
		Resources::Load<graphics::Texture>(L"PackMan1", L"..\\Resources\\img\\pacman\\1.png");
		Resources::Load<graphics::Texture>(L"PackMan2", L"..\\Resources\\img\\pacman\\2.png");
	}
}

//이번에 추가할 내용

//1. 카메라
//2. 크기 조정
//3. 스크립트