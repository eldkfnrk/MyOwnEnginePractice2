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
		//Initialize �Լ��� �����ߴ� �κ��� ���� �Լ��� ����� ����
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
		//for_each�� c++���� vector�� for������ ������ �� �� �� �����ϰ� ����ڰ� for_each���� ����� ������ �������� �ο��ϱ� ���ؼ� ����ϴ� std �̸� ������ �Լ��̴�.
		//ù ��° ���ڷδ� ���� �ּ� ��, �� ��° ���ڷδ� ����� ������ ���� null Ȥ�� ������ ���� �ּ�(�迭�� ������ ��Ҷ�� ���� �ȴ�.), �� ��° ���ڷδ� ������ �Լ� Ȥ�� �Լ� ��ü�� ���´�.
		//���� �� ��° ���ڷ� ���� ���� lambda��� ������ �Լ� ��ü�� �Լ� �����͸� ����ؾ� �ϴ� ��� �̸� ��ü�Ͽ� ����� �� �ִ� c++ �����̴�.
		//lambda�� '[captures](parameter)->return type{body}'�� ������ �Ǵµ� [captures]�κ��� �����ϰ�� ���°� ��¦ �ٸ� �� �Լ��� ����.
		//[captures]���� captures �κп� ������ ���� ������ ����� ������ ���ϸ� ���⿡ ���� ������ ����� �Լ����� ����ϵ��� �������� ���̴�.
		//std::for_each(mKeys.begin(), mKeys.end(), 
		//	[](Key& key) -> void { 
		//		updateKey(key);  //�� �κ����� ���� ������ �� �Ǵ� ������ ������ ���� ����
		//	});

		//�׷��� ���� for_each���� �� �� ���� �� ������ �߻��Ͽ��� ������ ������ ����ϴ� for���� ����ϰڴ�.
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
