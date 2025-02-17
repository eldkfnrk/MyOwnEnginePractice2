#pragma once

#include "..//MyFirstEngine_Source//mfeSceneManager.h"  //다른 프로젝트에 있고 참조하고 있는 상태가 아니라 정확한 파일의 위치를 기입해야 한다.
#include "mfePlayScene.h"
#include "mfeTitleScene.h"

//참조를 썼으면 상관없으나 헤더만 추가되어 있기 때문에 lib 파일도 추가하여 c++도 돌아가도록 설정(문제가 없으면 사용하지 않아도 괜찮다.)
//#ifdef _DEBUG
//#pragma comment(lib, "..//x64//debug//myfirstengine_window.lib")
//#else
//#pragma comment(lib, "..//x64//release//myfirstengine_window.lib")
//#endif

namespace mfe{
	void LoadScenes() {
		//씬의 순서에 맞춰서 CreateScene을 해주어야 한다.(그렇지 않으면 나와야 할 씬이 나오지 못 하는 상황이 발생할 수 있다.)
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"TitleScene");
	}
}