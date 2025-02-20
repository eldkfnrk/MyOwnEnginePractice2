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
}