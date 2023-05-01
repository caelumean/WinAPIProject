#include "Vestal.h"
#include "Time.h"
#include "SceneManager.h"
#include "Input.h"
#include "Resources.h"
#include "Transform.h"
#include "Animator.h"
#include "Scene.h"
#include "Object.h"

Vestal::Vestal()
{
}

Vestal::~Vestal()
{
}

void Vestal::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(300.0f, 860.0f));
	tr->SetScale(Vector2{ 0.5f, 0.5f });

	//D:\WinAPIProject\DarkestDungeon\Resources\Heroes\vestal
	Image* Idle = Resources::Load<Image>(L"vestal_Idle", L"..\\Resources\\Heroes\\vestal\\Vestal_Idle.bmp");
	Image* Move = Resources::Load<Image>(L"vestal_Move", L"..\\Resources\\Heroes\\vestal\\Vestal_Walk.bmp");
	Image* Combat = Resources::Load<Image>(L"vestal_Combat", L"..\\Resources\\Heroes\\vestal\\Vestal_Combat.bmp");

	mAnimator = AddComponent<Animator>();
	mAnimator->CreateAnimation(L"vestal_Idle", Idle, Vector2::Zero, 12, 1, 12, Vector2::Zero, 0.1f);
	mAnimator->CreateAnimation(L"vestal_Move", Move, Vector2::Zero, 12, 1, 12, Vector2::Zero, 0.08f);
	mAnimator->CreateAnimation(L"vestal_Combat", Combat, Vector2::Zero, 12, 1, 12, Vector2::Zero, 0.1f);

	mAnimator->Play(L"vestal_Idle", true);

	mState = eVestalState::Idle;

	GameObject::Initialize();
}


void Vestal::Update()
{
	GameObject::Update();

	switch (mState)
	{
	case Vestal::eVestalState::Move:
		move();
		break;
	case Vestal::eVestalState::Combat:
		combat();
		break;
	case Vestal::eVestalState::Idle:
		idle();
		break;
	default:
		break;
	}
}

void Vestal::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void Vestal::Release()
{
	GameObject::Release();
}

void Vestal::move()
{
	if (Input::GetKeyUp(eKeyCode::A)
		|| Input::GetKeyUp(eKeyCode::D))
	{
		mState = eVestalState::Idle;
		mAnimator->Play(L"vestal_Idle", true);
	}

	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();


	if (Input::GetKey(eKeyCode::A))
		pos.x -= 200.0f * Time::DeltaTime();

	if (Input::GetKey(eKeyCode::D))
		pos.x += 200.0f * Time::DeltaTime();


	tr->SetPos(pos);
}

void Vestal::idle()
{
	if (Input::GetKeyDown(eKeyCode::A)
		|| Input::GetKeyDown(eKeyCode::D))
	{
		mState = eVestalState::Move;
		mAnimator->Play(L"vestal_Move", true);
	}
}

void Vestal::combat()
{
}

void Vestal::death()
{
}
