#pragma once

//레이어로 지정할 enum을 저장하는 헤더 파일
namespace mfe {
	enum class eLayerType{
		None,
		BackGround,
		//필요한만큼 생성(Tree나 Character같은 것들)
		Player,
		Max=16,  //최대 16개라 명시(레이어가 엄청나게 많지는 않을 것이기에)
		//당연하게 필요에 따라서 최대 크기를 조절해서 사용하면 된다.
	};
}