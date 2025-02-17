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
	//�� ���� ���� ������ �˱� ���� ȭ�鿡 �� �̸� ����� ���� �ڵ�(�� �ڵ�� ���� ���ӿ����� �������� �ʰ� ���� ���鼭 �̰� ���� ������ Ȯ���ϴ� �뵵�� ���)
	wchar_t strSceneName[50] = L"Title Scene";  
	int len = wcsnlen_s(strSceneName, 50);
	//���� len�� ���� ������ C++���� string�� �ƴ� ���ڿ��� ���� �� ���ڸ� �迭�� �޾Ƽ� �����ϴµ� �̶� ��Ȯ�� ���ڿ��� ũ�⸦ �𸣱� ������ �迭�� ũ�� ����� �迭�� ���� �ް� �Ǵµ�
	//�׷��� �Ǹ� �Ʒ� TextOut�� �ټ� ��° ���ڿ� ��Ȯ�� ���ڿ� ũ�⸦ ���� �ʰ� ũ�⺸�� ū ���� �ְ� �Ǹ� NULL���ڰ� �Բ� ��µǴ� ������ �־ ��Ȯ�� ���ڿ��� ���̸� �˱� ���� �������.

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
