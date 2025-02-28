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
		//메인 카메라
		//벡터 값을 이렇게 설정한 이유는 카메라에게 주는 벡터 값은 카메라가 비추는 중앙 값이기 때문에 카메라가 비추고자 하는 것의 중앙 값을 주어야 하기 때문이다.
		//그래서 현재 화면의 크기인 672, 846의 중앙 값을 기본 위치 벡터 값으로 설정(이렇게 설정했어도 배경의 여백이 있다면 벡터 값을 변경하며 잘 맞추면 된다.
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(344.0f, 450.0f));  //카메라를 담당하는 오브젝트는 화면에 출력되면 안 되기에 가장 아래 layer인 None에다가 생성
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;
		//camera->AddComponent<PlayerScript>();  //카메라가 움직이나 테스트(실제 게임에서는 타겟을 따라다니도록 설정할 예정)

		//플레이어 오브젝트
		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
		SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
		sr->SetSize(Vector2(3.0f, 3.0f));  //맵의 크기의 3배로 윈도우를 만들었기 때문에 이에 맞게 이 오브젝트도 3배로 키워주었다.
		mPlayer->AddComponent<PlayerScript>();

		graphics::Texture* packmanTexture = Resources::Find<graphics::Texture>(L"PackMan0");
		sr->SetTexture(packmanTexture);

		//맵 오브젝트
		GameObject* bg = object::Instantiate<GameObject>(enums::eLayerType::BackGround);
		SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();
		bgSr->SetSize(Vector2(3.0f, 3.0f));  //맵의 크기의 3배로 윈도우를 만들었기 때문에 이에 맞게 이 오브젝트도 3배로 키워주었다.

		graphics::Texture* mapTexture = Resources::Find<graphics::Texture>(L"Map");
		bgSr->SetTexture(mapTexture);

		Scene::Initialize();
	}

	void PlayScene::Update()
	{
		Scene::Update();  //부모 클래스의 함수를 가져올 때는 풀네임을 사용하여 호출
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		//해당 씬에서 특정 키가 입력되면 다른 씬으로 이동하게 하기
		if (Input::GetKeyDown(eKeyCode::N)) {
			SceneManager::LoadScene(L"TitleScene");
		}
	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		//어떤 씬을 띄우는지 구분하기 위해 사용했으나 이제는 화면을 가리니 표시하지 않아도 된다.
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