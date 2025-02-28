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

		//�������� �ڸ�Ʈ - ������ �ϼ��Ǵ� ������ ������ �ϼ��Ǵ� ������ �ƴ� ���̴�. ������ �ϸ鼭 ������� ������ ū Ʋ�� �����ִ� ������ ������ ������ ������ ���� ���̴�.
	}

	void Camera::Update()
	{
		//���� ���󰡴� Ÿ�� ������Ʈ�� �ִٸ� ī�޶� �ٶ󺸴� ��ġ�� �ش� ������Ʈ�� ��ġ�� ����
		if (mTarget != nullptr) {
			Transform* tr = mTarget->GetComponent<Transform>();
			mLookPosition = tr->GetPosition();
		}

		//ī�޶��� �ٶ󺸴� ��ġ ���� ����
		Transform* cameraTr = GetOwner()->GetComponent<Transform>();
		mLookPosition = cameraTr->GetPosition();

		//ī�޶� ������Ʈ�� �� ī�޶��� ����� ��ġ�� ������Ʈ�� �Ǿ�� �ϴµ� �Ʒ��� ������ ī�޶� �̵��� �Ÿ��� �˾Ƴ��� �����̴�.
		//�� ������ �ڼ��� �����ϸ� �ٶ󺸴� ��ġ�� ī�޶��� �߾� ��ġ�� �ǹ��ϰ� �ػ󵵴� ī�޶� ���ߴ� ȭ���� ũ�⸦ �ǹ��Ѵ�.
		//�̶� �츮�� ���� ��ǥ�� (0,0) �ػ󵵴� (1000, 1000)�� ī�޶� ������ �ִٰ� �����غ���. �׷��� �ٶ󺸴� ��ġ�� (500,500)�� �ȴ�.
		//�׸��� ī�޶� �̵��Ͽ� �ٶ󺸴� ��ġ�� (1000,500)�� �Ǿ��ٸ� �̶� �̵� �Ÿ��� ���غ��ڸ� ������ ���� ���� ��ǥ�� �̵� �Ÿ��̴�.
		//�̸� ���ϱ� ���ؼ� �ٶ󺸴� ��ġ�� �ػ󵵿� 2�� ���� ���� ���ִ� ���̴�. �׷��� (1000,500) - ((1000,1000)/2) = (1000,500)-(500,500) = (500,0)
		//�׷��� ������ ������ ���� ������ ����Ͽ� �̵��� �Ÿ��� ���Ѵ�.
		mDistance = mLookPosition - (mResolution / 2.0f);  //�̵��� �Ÿ� = �ٶ󺸴� ��ġ - (�ػ� / 2.0f)
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