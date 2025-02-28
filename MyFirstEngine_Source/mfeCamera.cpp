#include "mfeCamera.h"
#include "mfeGameObject.h"
#include "mfeTransform.h"
#include "mfeApplication.h"

extern mfe::Application application;

namespace mfe {
	Camera::Camera() : Component(enums::eComponentType::Camera), mDistance(Vector2::Zero), mResolution(Vector2::Zero), mLookPosition(Vector2::Zero), mTarget(nullptr)
	{

	}

	void Camera::Initialize()
	{
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();

		//선생님의 코멘트 - 엔진이 완성되는 시점이 게임이 완성되는 시점은 아닐 것이다. 수업을 하면서 만들어진 엔진은 큰 틀을 보여주는 것이지 엔진의 정답이 되지는 않을 것이다.
	}

	void Camera::Update()
	{
		//만약 따라가는 타겟 오브젝트가 있다면 카메라가 바라보는 위치는 해당 오브젝트의 위치로 설정
		if (mTarget != nullptr) {
			Transform* tr = mTarget->GetComponent<Transform>();
			mLookPosition = tr->GetPosition();
		}

		//카메라의 바라보는 위치 정보 저장
		Transform* cameraTr = GetOwner()->GetComponent<Transform>();
		mLookPosition = cameraTr->GetPosition();

		//카메라를 업데이트할 때 카메라의 변경된 위치가 업데이트가 되어야 하는데 아래의 문장은 카메라가 이동한 거리를 알아내는 수식이다.
		//이 수식을 자세히 설명하면 바라보는 위치는 카메라의 중앙 위치를 의미하고 해상도는 카메라가 비추는 화면의 크기를 의미한다.
		//이때 우리는 시작 좌표는 (0,0) 해상도는 (1000, 1000)인 카메라를 가지고 있다고 가정해보자. 그러면 바라보는 위치는 (500,500)이 된다.
		//그리고 카메라가 이동하여 바라보는 위치가 (1000,500)이 되었다면 이때 이동 거리를 구해보자면 봐야할 것은 시작 좌표의 이동 거리이다.
		//이를 구하기 위해서 바라보는 위치에 해상도에 2를 나눈 값을 빼주는 것이다. 그러면 (1000,500) - ((1000,1000)/2) = (1000,500)-(500,500) = (500,0)
		//그렇기 때문에 다음과 같은 수식을 사용하여 이동한 거리를 구한다.
		mDistance = mLookPosition - (mResolution / 2.0f);  //이동한 거리 = 바라보는 위치 - (해상도 / 2.0f)
	}

	void Camera::LateUpdate()
	{

	}

	void Camera::Render(HDC hdc)
	{
	}

	Camera::~Camera()
	{
	}
}