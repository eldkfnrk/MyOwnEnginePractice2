#include "mfePlayer.h"
#include "mfeInput.h"
#include "mfeTransform.h"
#include "mfeTime.h"

namespace mfe {
	Player::Player()
	{
	}

	void Player::Initialize()
	{
		GameObject::Initialize();
	}

	void Player::Update()
	{
		GameObject::Update();
	}

	void Player::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		if (Input::GetKeyDown(eKeyCode::Right)) {
			Transform* tr = GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.x += 100.0f * Time::DeltaTime();
			tr->SetPos(pos);
		}
	}

	Player::~Player()
	{
	}
}
