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

			//지금까지는 위와 같은 방식으로 오브젝트들을 추가해 왔는데 이러면 오브젝트를 추가할 때마다 매번 이렇게 하면 번거롭기 때문에 이를 해소하기 위해 함수를 하나 만들 예정이다.
			//유니티는 instantiate함수를 호출하여 한 줄로 오브젝트를 원하는 위치에 원하는 각도로 추가할 수 있는데 이를 여기에도 만들어 편리하게 사용해보고자 한다.
			//아래는 이를 위의 코드를 instantiate함수를 이용하여 단축한 코드이다.

			//bg = object::Instantiate<Player>(enums::eLayerType::BackGround);  //위치는 기본 값인 0,0으로 오브젝트를 만드는 함수(위치를 지정하고 싶으면 아래와 같이 호출해야 한다.)
			bg = object::Instantiate<Player>(enums::eLayerType::BackGround, Vector2(100.0f, 100.0f));

			//Transform 정보는 당연히 들어가는 것이기에 디폴트로 함수에 넣어준 것이고 다른 컴포넌트들은 사용하는 것에 맞게 추가해주어야 한다.(사용 여부가 불명한 것들은 따로 추가한다는 의미)
			SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
			sr->ImageLoad(L"D:\\GameEnginePractice\\MyOwnEnginePractice-master\\Resources\\CloudOcean.png");
		}
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