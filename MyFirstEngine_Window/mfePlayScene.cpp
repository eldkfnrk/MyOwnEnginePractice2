#include "mfePlayScene.h"
#include "mfeGameObject.h"
#include "mfePlayer.h"
#include "mfeTransform.h"
#include "mfeSpriteRenderer.h"
#include "mfeInput.h"
#include "mfeTitleScene.h"
#include "mfeSceneManager.h"
#include "mfeLayer.h"
#include "mfeObject.h"

namespace mfe {
	PlayScene::PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		{
			//bg = new Player();
			//Transform* tr = bg->AddComponent<Transform>();

			//tr->SetPosition(Vector2(0, 0));

			//tr->SetName(L"TR");

			////SpriteRenderer* sr = pl->AddComponent<SpriteRenderer>();
			//SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();

			//sr->SetName(L"SR");

			//sr->ImageLoad(L"D:\\GameEnginePractice\\MyOwnEnginePractice-master\\Resources\\CloudOcean.png");
			//
			////AddGameObject(pl);
			////AddGameObject(bg);
			//AddGameObject(bg, enums::eLayerType::BackGround);

			//���ݱ����� ���� ���� ������� ������Ʈ���� �߰��� �Դµ� �̷��� ������Ʈ�� �߰��� ������ �Ź� �̷��� �ϸ� ���ŷӱ� ������ �̸� �ؼ��ϱ� ���� �Լ��� �ϳ� ���� �����̴�.
			//����Ƽ�� instantiate�Լ��� ȣ���Ͽ� �� �ٷ� ������Ʈ�� ���ϴ� ��ġ�� ���ϴ� ������ �߰��� �� �ִµ� �̸� ���⿡�� ����� ���ϰ� ����غ����� �Ѵ�.
			//�Ʒ��� �̸� ���� �ڵ带 instantiate�Լ��� �̿��Ͽ� ������ �ڵ��̴�.

			//bg = object::Instantiate<Player>(enums::eLayerType::BackGround);  //��ġ�� �⺻ ���� 0,0���� ������Ʈ�� ����� �Լ�(��ġ�� �����ϰ� ������ �Ʒ��� ���� ȣ���ؾ� �Ѵ�.)
			bg = object::Instantiate<Player>(enums::eLayerType::BackGround, Vector2(100.0f, 100.0f));

			//Transform ������ �翬�� ���� ���̱⿡ ����Ʈ�� �Լ��� �־��� ���̰� �ٸ� ������Ʈ���� ����ϴ� �Ϳ� �°� �߰����־�� �Ѵ�.(��� ���ΰ� �Ҹ��� �͵��� ���� �߰��Ѵٴ� �ǹ�)
			SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
			sr->ImageLoad(L"D:\\GameEnginePractice\\MyOwnEnginePractice-master\\Resources\\CloudOcean.png");
		}
	}

	void PlayScene::Update()
	{
		Scene::Update();  //�θ� Ŭ������ �Լ��� ������ ���� Ǯ������ ����Ͽ� ȣ��
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		//�ش� ������ Ư�� Ű�� �ԷµǸ� �ٸ� ������ �̵��ϰ� �ϱ�
		if (Input::GetKeyDown(eKeyCode::N)) {
			SceneManager::LoadScene(L"TitleScene");
		}
	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t strSceneName[50] = L"Play Scene";
		int len = wcsnlen_s(strSceneName, 50);

		TextOut(hdc, 0, 0, strSceneName, len);
	}

	void PlayScene::OnEnter()
	{

	}

	void PlayScene::OnExit()
	{
		//Transform* tr = bg->GetComponent<Transform>();
		//tr->SetPosition(Vector2(0, 0));
	}

	PlayScene::~PlayScene()
	{
	}
}