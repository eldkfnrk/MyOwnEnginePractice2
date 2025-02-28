#pragma once

namespace mfe::enums {
	//레이어로 지정할 enum
	enum class eLayerType{
		None,
		BackGround,
		//필요한만큼 생성(Tree나 Character같은 것들)
		Player,
		Max=16,  //최대 16개라 명시(레이어가 엄청나게 많지는 않을 것이기에)
		//당연하게 필요에 따라서 최대 크기를 조절해서 사용하면 된다.
	};

	//리소스의 타입으로 사용할 enum
	//여기에 필요한 리소스가 있으면 추가해서 사용하면 된다.
	enum class eResourceType {
		Texture,  //이미지 타입
		//이 리소스들은 3d로 게임을 만들 때 사용되는 리소스 종류들
		//Mesh,  
		//Shader,
		AudioClip,  //사운드 타입
		Prefab,  //데이터 저장할 때 사용할 타입
		End,
	};

	//컴포넌트 간 업데이트 순서를 지켜야 게임 오브젝트가 일정한 순서를 가지고 컴포넌트를 업데이트 하는데 이는 게임 오브젝트의 컴포넌트 업데이트 순서가 벡터에 push_back 순서로 진행하는 것보다 
	//일정한 순서를 정해놓고 이를 따르도록 만들어야 한다.
	//그러기 위한 enum을 정의
	enum class eComponentType {
		//아래의 순서가 컴포넌트의 업데이트 순서가 될 것이다.
		Transform,
		SpriteRenderer,
		Script,
		Camera,  //카메라는 항상 제일 나중에 업데이트 되어야 하기 때문에 enum에서 End 바로 위에 항상 있어야 한다. 사실상 마지막에 있어야 한다는 의미(화면 출력은 모든 동작을 반영해 알맞게 출력해야 하기 때문이다.)
		End,
	};
}