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

namespace mfe {
	PlayScene::PlayScene()
	{
	}

	void PlayScene::Initialize()
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

		//sr->ImageLoad(L"D:\\GameEnginePractice\\MyOwnEnginePractice-master\\Resources\\CloudOcean.png");  //여기에 인자로 전달된 경로는 절대 경로로 다른 컴퓨터에서 동작시키면 이미지 출력이 안 된다.
		//이런 경우를 방지하기 위해서는 상대 경로로 출력되게 만들어야 하고 이를 관리하는 것이 리소스 시스템이다.
		//이제 스프라이트렌더러 클래스가 아닌 텍스쳐 클래스에서 이미지 리소스와 관련된 일을 관장하니 아래와 같이 텍스쳐 클래스를 사용해야 한다.

		//graphics::Texture* tex = new graphics::Texture(enums::eResourceType::Texture);

		//tex->Load(L"D:\\GameEnginePractice\\MyOwnEnginePractice-master\\Resources\\CloudOcean.png");
		//이렇게 이미지 로드를 해서 이미지 로드를 성공하게 되면 이제 화면에 출력을 해야 하는데 이제 출력은 스프라이트렌더러 클래스에서 이루어지기 된다.
		//그럴려면 이미지를 가지고 있는 텍스쳐 클래스 객체를 스프라이트렌더러 클래스에서 사용이 되어야 한다.
		//스프라이트렌더러 클래스에서 해당 리소스를 가지고 와서 사용하여야 되는데 이제 이것을 가지고 오려면 씬매니저가 씬을 사용하는데 관리해주는 것처럼 리소스도 관리해주는 클래스가 필요하게 된다.
		//그 클래스를 통해 접근해서 가지고 와서 사용할 수 있어야 한다. 즉, 어디서든 리소스가 사용 가능하게 해주는 리소스 관리 클래스가 필요하다.
		//그 역할을 할 클래스가 바로 Resources이다.
		//이 클래스가 있으면 위와 같이 리소스를 직접 씬에서 로드하는 것이 아닌 리소스 관리 클래스를 통해서 리소스를 로드하게 된다.

		//게임 오브젝트들은 만들기 전에 리소스들을 전부 Load 해두면 좋다.
		//그래서 씬을 로드해주는 헤더 파일을 만들었듯이 리소스들을 전부 Load 해주는 헤더 파일을 하나 만들고 씬을 만들 때 이를 호출해서 한 번에 작업을 완료한다.
		//호출은 씬에서 하는 것이 아니라 메인 함수에서 윈도우가 만들어지는 과정 중에 이루어지게 된다.
		//왜냐하면, 리소스를 씬마다 호출하는 것은 메모리 손실도 크고 굳이 그렇게 할 이유도 없기 때문에 한 번만 호출하면 되고 그렇다면 이 호출은 윈도우 생성과 동시에 하면 되기에 이렇게 작업이 이루어진다.

		//이제 리소스 로드가 모두 진행됐다고 가정하고 이후의 작업을 보아야 한다.
		//리소스 로드까지 끝마친 상황에서 이제 화면 출력을 해야 하는데 이때 화면 출력과 관련된 역할은 스프라이트렌더러 컴포넌트가 진행하기 때문에 이 컴포넌트를 설정해주어야 한다.
		//사용할 텍스쳐 리소스를 스프라이트렌더러 컴포넌트에 전달
		//전달할 때는 저번에 얘기했듯이 한 줄로 축약할 수 있어도 데이터를 저장하고 이를 활용하는 편이 더 좋은 코드이기에 이와 같이 사용한다.
		graphics::Texture* tex = Resources::Find<graphics::Texture>(L"BG");
		sr->SetTexture(tex);

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