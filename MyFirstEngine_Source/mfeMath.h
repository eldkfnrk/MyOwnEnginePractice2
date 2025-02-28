#pragma once

namespace mfe::math {
	struct Vector2
	{
		//1.0f, 1.0f와 0.0f, 0.0f는 자주 쓰여지는 값들이기 때문에 정저 변수로 만들어 놓아서 쓰기 편하게 만들어 놓는다.
		static Vector2 One;  //대표적인 예시로 리소스 사이즈가 있다.(기본일 때 1.0f, 1.0f를 사용하기 때문)
		static Vector2 Zero;

		float x;
		float y;

		Vector2() : x(0.0f), y(0.0f) {
			
		}

		Vector2(float _x, float _y) : x(_x), y(_y) {

		}

		Vector2 operator+(Vector2 other) {
			return Vector2(x + other.x, y + other.y);
		}
		
		Vector2 operator-(Vector2 other) {
			return Vector2(x - other.x, y - other.y);
		}

		Vector2 operator/(float value) {
			return Vector2(x / value, y / value);
		}
	};
}
