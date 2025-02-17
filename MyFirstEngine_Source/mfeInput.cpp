#include "mfeInput.h"

namespace mfe {
	std::vector<Input::Key> Input::Keys = {};

	int ASCII[(UINT)eKeyCode::End] = {
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP, VK_SPACE,
	};

	void Input::Initialize()
	{
		createKeys();
	}

	void Input::Update()
	{
		updateKeys();
	}
	void Input::createKeys()
	{
		//Initialize 함수에 정의했던 부분을 따로 함수를 만들어 관리
		Keys.resize((UINT)eKeyCode::End);

		for (size_t i = 0; i < (UINT)eKeyCode::End; i++) {
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			Keys.push_back(key);
		}
	}
	
	void Input::updateKeys()
	{
		//for_each는 c++에서 vector를 for문으로 돌리려 할 때 더 간결하고 사용자가 for_each문의 기능을 정의해 유연성을 부여하기 위해서 사용하는 std 이름 공간의 함수이다.
		//첫 번째 인자로는 시작 주소 값, 두 번째 인자로는 요소의 마지막 다음 null 혹은 쓰레기 값의 주소(배열의 마지막 요소라고 보면 된다.), 세 번째 인자로는 동작할 함수 혹은 함수 객체가 들어온다.
		//밑의 세 번째 인자로 들어온 것은 lambda라는 것으로 함수 객체나 함수 포인터를 사용해야 하는 경우 이를 대체하여 사용할 수 있는 c++ 문법이다.
		//lambda는 '[captures](parameter)->return type{body}'로 구성이 되는데 [captures]부분을 제외하고는 형태가 살짝 다를 뿐 함수와 같다.
		//[captures]에서 captures 부분에 들어오는 것은 변수나 상수로 간단히 말하면 여기에 들어온 변수나 상수는 함수에서 사용하도록 가져오는 것이다.
		//std::for_each(mKeys.begin(), mKeys.end(), 
		//	[](Key& key) -> void { 
		//		updateKey(key);  //이 부분으로 인자 전달이 안 되는 것인지 동작이 되지 않음
		//	});

		//그러나 위의 for_each문은 알 수 없는 논리 오류가 발생하여서 지금은 기존에 사용하던 for문을 사용하겠다.
		for (size_t i = 0; i < Keys.size(); i++) {
			if (GetAsyncKeyState(ASCII[i]) & 0x8000) {  
				if (Keys[i].bPressed == true) {  
					Keys[i].state = eKeyState::Pressed;
				}
				else {
					Keys[i].state = eKeyState::Down;
				}

				Keys[i].bPressed = true;  
			}
			else {  
				if (Keys[i].bPressed == true) {  
					Keys[i].state = eKeyState::Up;
				}
				else {
					Keys[i].state = eKeyState::None;
				}

				Keys[i].bPressed = false; 
			}
		}
	}
}
