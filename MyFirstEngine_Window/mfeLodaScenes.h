#pragma once

#include "..//MyFirstEngine_Source//mfeSceneManager.h"  //�ٸ� ������Ʈ�� �ְ� �����ϰ� �ִ� ���°� �ƴ϶� ��Ȯ�� ������ ��ġ�� �����ؾ� �Ѵ�.
#include "mfePlayScene.h"
#include "mfeTitleScene.h"

//������ ������ ��������� ����� �߰��Ǿ� �ֱ� ������ lib ���ϵ� �߰��Ͽ� c++�� ���ư����� ����(������ ������ ������� �ʾƵ� ������.)
//#ifdef _DEBUG
//#pragma comment(lib, "..//x64//debug//myfirstengine_window.lib")
//#else
//#pragma comment(lib, "..//x64//release//myfirstengine_window.lib")
//#endif

namespace mfe{
	void LoadScenes() {
		//���� ������ ���缭 CreateScene�� ���־�� �Ѵ�.(�׷��� ������ ���;� �� ���� ������ �� �ϴ� ��Ȳ�� �߻��� �� �ִ�.)
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"TitleScene");
	}
}