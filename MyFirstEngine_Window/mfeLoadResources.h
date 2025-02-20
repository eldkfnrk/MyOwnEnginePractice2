#pragma once

#include "..//MyFirstEngine_Source//mfeResources.h"  //다른 프로젝트에 있고 참조하고 있는 상태가 아니라 정확한 파일의 위치를 기입해야 한다.
#include "..//MyFirstEngine_Source//mfeTexture.h"

namespace mfe {
	void LoadResources() {
		//해당 경로의 리소스를 로드(첫 번째 인자는 불러오는 리소스에게 붙일 이름)
		Resources::Load<graphics::Texture>(L"BG", L"D:\\GameEnginePractice\\MyOwnEnginePractice-master\\Resources\\CloudOcean.png");
	}
}