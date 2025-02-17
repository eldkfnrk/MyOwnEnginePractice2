#include "mfeTitleScene.h"
#include "mfeInput.h"
#include "mfeTitleScene.h"
#include "mfeSceneManager.h"

mfe::TitleScene::TitleScene()
{
}

void mfe::TitleScene::Initialize()
{
}

void mfe::TitleScene::Update()
{
	Scene::Update();
}

void mfe::TitleScene::LateUpdate()
{
	Scene::LateUpdate();

	if (Input::GetKeyDown(eKeyCode::N)) {
		SceneManager::LoadScene(L"PlayScene");
	}
}

void mfe::TitleScene::Render(HDC hdc)
{
	Scene::Render(hdc);
	//이 씬이 무슨 씬인지 알기 위해 화면에 씬 이름 출력을 위한 코드(이 코드는 실제 게임에서는 사용되지는 않고 현재 배우면서 이게 무슨 씬인지 확인하는 용도로 사용)
	wchar_t strSceneName[50] = L"Title Scene";  
	int len = wcsnlen_s(strSceneName, 50);
	//위의 len을 만든 이유는 C++에선 string이 아닌 문자열을 만들 때 문자를 배열로 받아서 구현하는데 이때 정확한 문자열의 크기를 모르기 때문에 배열을 크게 만들고 배열에 값을 받게 되는데
	//그렇게 되면 아래 TextOut의 다섯 번째 인자에 정확한 문자열 크기를 넣지 않고 크기보다 큰 수를 넣게 되면 NULL문자가 함께 출력되는 문제가 있어서 정확한 문자열의 길이를 알기 위해 만들었다.

	TextOut(hdc, 0, 0, strSceneName, len);
}

void mfe::TitleScene::OnEnter()
{

}

void mfe::TitleScene::OnExit()
{

}

mfe::TitleScene::~TitleScene()
{
}
