#include "Camera.h"
#include "Application.h"
#include "GameObject.h"
#include "Transform.h"
#include "Input.h"
#include "Time.h"
#include "Image.h"

extern Application application;

// �ʱ�ȭ
Vector2 Camera::mResolution = Vector2::Zero;
Vector2 Camera::mLookPosition = Vector2::Zero;
Vector2 Camera::mDistance = Vector2::Zero;
GameObject* Camera::mTarget = nullptr;

// statice�̴ϱ� �� �ʱ�ȭ
Camera::eCameraEffectType Camera::mType = Camera::eCameraEffectType::None;
class Image* Camera::mCutton = nullptr;
float Camera::mCuttonAlpha = 1.0f;
float Camera::mAlphaTime = 0.0f;
float Camera::mEndTime = 5.0f;

void Camera::Initialize()
{
	// Application�� �ػ� ��������
	mResolution.x = application.GetWidth();
	mResolution.y = application.GetHeight();
	mLookPosition = (mResolution / 2.0f);

	// Camera FadeIn ȿ���� ����
	// FadeIn ȿ���� �ֱ� ������ None���� �ٲٸ� �ȴ�
	//mType = eCameraEffectType::FadeIn;
	mType = eCameraEffectType::None;
	mCutton = Image::Create(L"Cutton", mResolution.x, mResolution.y, RGB(0, 0, 0));
}

void Camera::Update()
{
	if (Input::GetKey(eKeyCode::LEFT))
		mLookPosition.x -= 100.0f * Time::DeltaTime();

	if (Input::GetKey(eKeyCode::RIGHT))
		mLookPosition.x += 100.0f * Time::DeltaTime();

	if (Input::GetKey(eKeyCode::UP))
		mLookPosition.y -= 100.0f * Time::DeltaTime();

	if (Input::GetKey(eKeyCode::DOWN))
		mLookPosition.y += 100.0f * Time::DeltaTime();

	// Ÿ���� ������ 
	// ���Ӹ��� �ٸ��� Ÿ���� �ʿ����� ������
	if (mTarget != nullptr)
	{
		// �� ĳ���� ���󰡰ڴ�.
		mLookPosition
			= mTarget->GetComponent<Transform>()->GetPos();
	}

	if (mAlphaTime < mEndTime)
	{
		//255 - > 1
		// ��� �ð��� ���ش�
		mAlphaTime += Time::DeltaTime();
		// ��ü�� 5�ʰ� ���� 1�ʶ�� 1/5 �� 20%
		// ��� �ö󰣴� 1�� ������� ������
		// ���� ���� ���´�.
		float ratio = (mAlphaTime / mEndTime);

		if (mType == eCameraEffectType::FadeIn)
		{
			// ���� ���ڰ� 0�� ����� ����.
			mCuttonAlpha = 1.0f - ratio;
		}
		else if (mType == eCameraEffectType::FadeOut)
		{
			// ���� ���ڰ� 1�� ���������.
			mCuttonAlpha = ratio;
		}
		else
		{

		}
	}

	mDistance = mLookPosition - (mResolution / 2.0f);
}

void Camera::Render(HDC hdc)
{
	if (mAlphaTime < mEndTime
		&& mType == eCameraEffectType::FadeIn)
	{
		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = 0;
		func.SourceConstantAlpha = (BYTE)(255.0f * mCuttonAlpha);

	
		AlphaBlend(hdc, 0, 0
			, mResolution.x, mResolution.y
			, mCutton->GetHdc()
			, 0, 0
			, mCutton->GetWidth(), mCutton->GetHeight()
			, func);
	}
}

void Camera::Clear()
{
	mResolution.x = application.GetWidth();
	mResolution.y = application.GetHeight();
	mLookPosition = (mResolution / 2.0f);
	mDistance = Vector2::Zero;
}

