#pragma once
#include "mfeCamera.h"

namespace mfe::renderer {
	//카메라가 비추는 화면을 렌더하기 위한 파일
	extern Camera* mainCamera;  //이런 전역 변수가 있다는 것을 다른 파일들에게 알린다.(extern을 쓰면 외부에서 이 변수가 있는지 알게 되면서 가져다 쓸 수 있다.)
}