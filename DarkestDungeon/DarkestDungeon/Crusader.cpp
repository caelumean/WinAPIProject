#include "Crusader.h"
#include "Time.h"
#include "SceneManager.h"
#include "Input.h"
#include "yaResources.h"
#include "Transform.h"
#include "Animator.h"
#include "Collider.h"
#include "Scene.h"

Crusader::Crusader()
{
}

Crusader::~Crusader()
{
}

void Crusader::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(800.0f, 980.0f));
	tr->SetScale(Vector2{ 0.6f, 0.5f });

	Image* mImage = Resources::Load<Image>(L"crusader_Idle", L"..\\Resources\\Heroes\\crusader\\crusader_Idle.bmp");
	Image* mImage2 = Resources::Load<Image>(L"crusader_walk", L"..\\Resources\\Heroes\\crusader\\crusader_Walk.bmp");
	Image* mImage3 = Resources::Load<Image>(L"crusader_combat", L"..\\Resources\\Heroes\\crusader\\crusader_Combat.bmp");
	
	mAnimator = AddComponent<Animator>();
	mAnimator->CreateAnimation(L"crusader_Idle", mImage, Vector2::Zero, 12, 1, 12, Vector2::Zero, 0.1f);
	mAnimator->CreateAnimation(L"crusader_walk", mImage2, Vector2::Zero, 12, 1, 12, Vector2::Zero, 0.08f);
	mAnimator->CreateAnimation(L"crusader_combat", mImage3, Vector2::Zero, 12, 1, 12, Vector2::Zero, 0.1f);

	mAnimator->Play(L"crusader_Idle", true);
	Collider* collider = AddComponent<Collider>();
	collider->SetCenter(Vector2(-150.0f, -580.0f));

	mState = eCrusaderState::Idle;

	GameObject::Initialize();
}

void Crusader::Update()
{
	GameObject::Update();

	switch (mState)
	{
	case Crusader::eCrusaderState::Walk:
		walk();
		break;
	case Crusader::eCrusaderState::Combat:
		combat();
		break;
	case Crusader::eCrusaderState::Idle:
		idle();
		break;
	default:
		break;
	}
	/*
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	if (Input::GetKeyState(eKeyCode::A) == eKeyState::Pressed)
	{
		pos.x -= 100.0f * Time::DeltaTime();
	}

	if (Input::GetKeyState(eKeyCode::D) == eKeyState::Pressed)
	{
		pos.x += 100.0f * Time::DeltaTime();
	}

	tr->SetPos(pos);
	*/
}


void Crusader::Render(HDC hdc)
{
	GameObject::Render(hdc);
	/*
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	mTime += Time::DeltaTime();

	if (mIdx >= 12)
	{
		mIdx = 0;
	}

	if (mTime > 0.1f)
	{
		mIdx++;
		mTime = 0.0f;
	}

	TransparentBlt(hdc, pos.x, pos.y+380, 250, 300
		, mImage->GetHdc(), (400 * mIdx), 0, 400, 590, RGB(255, 0, 255));
	*/
	
}

void Crusader::Release()
{
	GameObject::Release();
}

void Crusader::walk()
{
	if (Input::GetKeyUp(eKeyCode::A)
		|| Input::GetKeyUp(eKeyCode::D))
	{
		mState = eCrusaderState::Idle;
		mAnimator->Play(L"crusader_Idle", true);
	}

	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	if (Input::GetKey(eKeyCode::A))
		pos.x -= 150.0f * Time::DeltaTime();

	if (Input::GetKey(eKeyCode::D))
		pos.x += 150.0f * Time::DeltaTime();


	tr->SetPos(pos);
}

void Crusader::combat()
{
}

void Crusader::idle()
{
	if (Input::GetKeyDown(eKeyCode::A)
		|| Input::GetKeyDown(eKeyCode::D))
	{
		mState = eCrusaderState::Walk;
		mAnimator->Play(L"crusader_walk", true);
	}

}
