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
#include "mfeTexture.h"
#include "mfeResources.h"
#include "mfePlayerScript.h"
#include "mfeCamera.h"
#include "mfeRenderer.h"

namespace mfe {
	PlayScene::PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		//���� ī�޶�
		//���� ���� �̷��� ������ ������ ī�޶󿡰� �ִ� ���� ���� ī�޶� ���ߴ� �߾� ���̱� ������ ī�޶� ���߰��� �ϴ� ���� �߾� ���� �־�� �ϱ� �����̴�.
		//�׷��� ���� ȭ���� ũ���� 672, 846�� �߾� ���� �⺻ ��ġ ���� ������ ����(�̷��� �����߾ ����� ������ �ִٸ� ���� ���� �����ϸ� �� ���߸� �ȴ�.
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(344.0f, 450.0f));  //ī�޶� ����ϴ� ������Ʈ�� ȭ�鿡 ��µǸ� �� �Ǳ⿡ ���� �Ʒ� layer�� None���ٰ� ����
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;
		//camera->AddComponent<PlayerScript>();  //ī�޶� �����̳� �׽�Ʈ(���� ���ӿ����� Ÿ���� ����ٴϵ��� ������ ����)

		//�÷��̾� ������Ʈ
		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
		SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
		sr->SetSize(Vector2(3.0f, 3.0f));  //���� ũ���� 3��� �����츦 ������� ������ �̿� �°� �� ������Ʈ�� 3��� Ű���־���.
		mPlayer->AddComponent<PlayerScript>();

		graphics::Texture* packmanTexture = Resources::Find<graphics::Texture>(L"PackMan0");
		sr->SetTexture(packmanTexture);

		//�� ������Ʈ
		GameObject* bg = object::Instantiate<GameObject>(enums::eLayerType::BackGround);
		SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();
		bgSr->SetSize(Vector2(3.0f, 3.0f));  //���� ũ���� 3��� �����츦 ������� ������ �̿� �°� �� ������Ʈ�� 3��� Ű���־���.

		graphics::Texture* mapTexture = Resources::Find<graphics::Texture>(L"Map");
		bgSr->SetTexture(mapTexture);

		Scene::Initialize();
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

		//� ���� ������ �����ϱ� ���� ��������� ������ ȭ���� ������ ǥ������ �ʾƵ� �ȴ�.
		//wchar_t strSceneName[50] = L"Play Scene";
		//int len = wcsnlen_s(strSceneName, 50);

		//TextOut(hdc, 0, 0, strSceneName, len);
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