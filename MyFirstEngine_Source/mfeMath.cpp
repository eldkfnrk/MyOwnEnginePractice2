#include "mfeMath.h"

namespace mfe::math {
	//구조체의 정적 변수이기 때문에 당연히 초기화를 반드시 해주어야 한다.
	Vector2 Vector2::One = Vector2(1.0f, 1.0f);
	Vector2 Vector2::Zero = Vector2(0.0f, 0.0f);
}