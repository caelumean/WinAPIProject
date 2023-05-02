#include "HighwayMan.h"
#include "Time.h"
#include "SceneManager.h"
#include "Input.h"
#include "Resources.h"
#include "Transform.h"
#include "Animator.h"
#include "Scene.h"
#include "Object.h"

HighwayMan::HighwayMan()
{
}

HighwayMan::~HighwayMan()
{
}

void HighwayMan::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(585.0f, 880.0f));
	tr->SetScale(Vector2{ 0.5f, 0.5f });

	Image* Idle = Resources::Load<Image>(L"highwayman_Idle", L"..\\Resources\\Heroes\\highwayman\\highwayMan_Idle.bmp");
	Image* Move = Resources::Load<Image>(L"highwayman_Move", L"..\\Resources\\Heroes\\highwayman\\highwayMan_Walk.bmp");

	mAnimator = AddComponent<Animator>();
	mAnimator->CreateAnimation(L"highwayman_Idle", Idle, Vector2::Zero, 12, 1, 12, Vector2::Zero, 0.1f);
	mAnimator->CreateAnimation(L"highwayman_Move", Move, Vector2::Zero, 12, 1, 12, Vector2::Zero, 0.08f);

	mAnimator->Play(L"highwayman_Idle", true);

	mState = eHighwayManState::Idle;

	GameObject::Initialize();
}

void HighwayMan::Update()
{
	GameObject::Update();

	switch (mState)
	{
	case HighwayMan::eHighwayManState::Move:
		move();
		break;
	case HighwayMan::eHighwayManState::Idle:
		idle();
		break;
	default:
		break;
	}
}

void HighwayMan::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void HighwayMan::Release()
{
	GameObject::Release();
}

void HighwayMan::move()
{
	if (Input::GetKeyUp(eKeyCode::A)
		|| Input::GetKeyUp(eKeyCode::D))
	{
		mState = eHighwayManState::Idle;
		mAnimator->Play(L"highwayman_Idle", true);
	}

	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	if (Input::GetKey(eKeyCode::A))
		pos.x -= 200.0f * Time::DeltaTime();

	if (Input::GetKey(eKeyCode::D))
		pos.x += 200.0f * Time::DeltaTime();


	tr->SetPos(pos);
}

void HighwayMan::idle()
{
	if (Input::GetKeyDown(eKeyCode::A)
		|| Input::GetKeyDown(eKeyCode::D))
	{
		mState = eHighwayManState::Move;
		mAnimator->Play(L"highwayman_Move", true);
	}
}

void HighwayMan::death()
{
}
