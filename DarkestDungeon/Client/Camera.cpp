#include "Camera.h"
#include "Application.h"
#include "GameObject.h"
#include "Transform.h"
#include "Input.h"
#include "Time.h"
#include "Image.h"

extern Application application;

const float CameraSpeed = 200.0f;
// 초기화
Vector2 Camera::mResolution = Vector2::Zero;
Vector2 Camera::mLookPosition = Vector2::Zero;
Vector2 Camera::mDistance = Vector2::Zero;
GameObject* Camera::mTarget = nullptr;

float Camera::MinX = 0.0f;
float Camera::MaxX = 0.0f;

void Camera::Initialize()
{
	// Application의 해상도 가져오기
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

	// 타겟이 있으면 
	// 게임마다 다르다 타켓이 필요한지 안한지
	if (mTarget != nullptr)
	{
		// 내 캐릭터 따라가겠다.
		mLookPosition = mTarget->GetComponent<Transform>()->GetPos() + Vector2(80.0f, -450.0f);
		/*mLookPosition
			= mTarget->GetComponent<Transform>()->GetPos();*/

		// 카메라 최대 이동거리를 넘어가면 조정
		if (mLookPosition.x <= MinX)
			mLookPosition.x = MinX;
		if (mLookPosition.x >= MaxX)
			mLookPosition.x = MaxX;
	}

	//무조건 LookPosition이 가운대로오게끔
	mDistance = mLookPosition - (mResolution / 2.0f);
}

void Camera::Clear()
{
	mResolution.x = application.GetWidth();
	mResolution.y = application.GetHeight();
	mLookPosition = (mResolution / 2.0f);
	mDistance = Vector2::Zero;
}

