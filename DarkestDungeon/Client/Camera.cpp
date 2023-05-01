#include "Camera.h"
#include "Application.h"
#include "GameObject.h"
#include "Transform.h"
#include "Input.h"
#include "Time.h"
#include "Image.h"

extern Application application;

const float CameraSpeed = 200.0f;
// �ʱ�ȭ
Vector2 Camera::mResolution = Vector2::Zero;
Vector2 Camera::mLookPosition = Vector2::Zero;
Vector2 Camera::mDistance = Vector2::Zero;
GameObject* Camera::mTarget = nullptr;

float Camera::MinX = 0.0f;
float Camera::MaxX = 0.0f;

void Camera::Initialize()
{
	// Application�� �ػ� ��������
	mResolution.x = application.GetWidth();
	mResolution.y = application.GetHeight();
	mLookPosition = (mResolution / 2.0f);


}

void Camera::Update()
{

	if (Input::GetKey(eKeyCode::A))
		mLookPosition.x -= CameraSpeed * Time::DeltaTime();

	if (Input::GetKey(eKeyCode::D))
		mLookPosition.x += CameraSpeed * Time::DeltaTime();

	//if (Input::GetKey(eKeyCode::UP))
	//	mLookPosition.y -= 100.0f * Time::DeltaTime();

	//if (Input::GetKey(eKeyCode::DOWN))
	//	mLookPosition.y += 100.0f * Time::DeltaTime();

	// Ÿ���� ������ 
	// ���Ӹ��� �ٸ��� Ÿ���� �ʿ����� ������
	if (mTarget != nullptr)
	{
		// �� ĳ���� ���󰡰ڴ�.
		mLookPosition = mTarget->GetComponent<Transform>()->GetPos() + Vector2(80.0f, -450.0f);
		/*mLookPosition
			= mTarget->GetComponent<Transform>()->GetPos();*/

		// ī�޶� �ִ� �̵��Ÿ��� �Ѿ�� ����
		if (mLookPosition.x <= MinX)
			mLookPosition.x = MinX;
		if (mLookPosition.x >= MaxX)
			mLookPosition.x = MaxX;
	}

	//������ LookPosition�� �����ο��Բ�
	mDistance = mLookPosition - (mResolution / 2.0f);
}

void Camera::Clear()
{
	mResolution.x = application.GetWidth();
	mResolution.y = application.GetHeight();
	mLookPosition = (mResolution / 2.0f);
	mDistance = Vector2::Zero;
}

