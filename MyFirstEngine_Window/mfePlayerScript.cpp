#include "mfePlayerScript.h"
#include "mfeInput.h"
#include "mfeTransform.h"
#include "mfeTime.h"
#include "mfeGameObject.h"

namespace mfe {
	PlayerScript::PlayerScript()
	{
	}

	void PlayerScript::Initialize()
	{
	}

	void PlayerScript::Update()
	{
		//기존에 Player오브젝트에서 직접 하던 것을 이제 해당 오브젝트의 스크립트에서 수행
		if (Input::GetKey(eKeyCode::Right)) {
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.x += 100.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}

		if (Input::GetKey(eKeyCode::Left)) {
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.x -= 100.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}

		if (Input::GetKey(eKeyCode::Up)) {
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.y -= 100.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}

		if (Input::GetKey(eKeyCode::Down)) {
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.y += 100.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
	}

	void PlayerScript::LateUpdate()
	{
	}

	void PlayerScript::Render(HDC hdc)
	{
		
	}

	PlayerScript::~PlayerScript()
	{
	}
}