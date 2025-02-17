#pragma once
#include "CommonInclude.h"

namespace mfe {
	//키 입력과 관련된 작업 수행
	enum class eKeyState {
		Down,
		Pressed,
		Up, 
		None,
	};

	enum class eKeyCode {  //키 구분(기존 알파벳만 있던 키에 방향키 추가)
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M, 
		Left, Right, Down, Up, Space,
		End,
	};

	class Input 
	{
	public:
		struct Key
		{
			eKeyCode keyCode;  //어떤 키가 입력되는지 알기 위한 변수
			eKeyState state;  //키 입력 상태를 나타내는 변수
			bool bPressed;  //키가 눌려있는지 알기 위한 변수
		};

		static void Initialize();
		static void Update();
		
		static bool GetKeyDown(eKeyCode code) {  //down이면 true 반환
			return Keys[(UINT)code].state == eKeyState::Down;  
		}
		static bool GetKey(eKeyCode code) {  //pressed이면 true 반환
			return Keys[(UINT)code].state == eKeyState::Pressed;
		}
		static bool GetKeyUp(eKeyCode code) {  //up이면 true 반환
			return Keys[(UINT)code].state == eKeyState::Up;
		}

	private:
		static void createKeys();
		static void updateKeys();

		static std::vector<Key> Keys;
	};
}
