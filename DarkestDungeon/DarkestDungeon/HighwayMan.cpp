#include "HighwayMan.h"
#include "Time.h"
#include "SceneManager.h"
#include "Input.h"
#include "yaResources.h"
#include "Transform.h"
#include "Animator.h"
#include "Collider.h"
#include "Scene.h"

HighwayMan::HighwayMan()
{
}

HighwayMan::~HighwayMan()
{
}

void HighwayMan::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(630.0f, 960.0f));
	tr->SetScale(Vector2{ 0.6f, 0.5f });
	
	//D:\WinAPIProject\DarkestDungeon\Resources\Heroes\highwayman
	Image* mImage = Resources::Load<Image>(L"highwayman_Idle", L"..\\Resources\\Heroes\\highwayman\\highwayMan_Idle.bmp");
	Image* mImage2 = Resources::Load<Image>(L"highwayman_walk", L"..\\Resources\\Heroes\\highwayman\\highwayMan_Walk.bmp");
	Image* mImage3 = Resources::Load<Image>(L"highwayman_combat", L"..\\Resources\\Heroes\\highwayman\\highwayMan_Combat.bmp");

	mAnimator = AddComponent<Animator>();
	mAnimator->CreateAnimation(L"highwayman_Idle", mImage, Vector2::Zero, 12, 1, 12, Vector2::Zero, 0.1f);
	mAnimator->CreateAnimation(L"highwayman_walk", mImage2, Vector2::Zero, 12, 1, 12, Vector2::Zero, 0.08f);
	mAnimator->CreateAnimation(L"highwayman_combat", mImage3, Vector2::Zero, 12, 1, 12, Vector2::Zero, 0.1f);

	mAnimator->Play(L"highwayman_Idle", true);
	Collider* collider = AddComponent<Collider>();
	collider->SetCenter(Vector2(-150.0f, -560.0f));

	mState = eHighwayManState::Idle;

	GameObject::Initialize();
}

void HighwayMan::Update()
{
	GameObject::Update();

	switch (mState)
	{
	case HighwayMan::eHighwayManState::Walk:
		walk();
		break;
	case HighwayMan::eHighwayManState::Combat:
		combat();
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

void HighwayMan::walk()
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
		pos.x -= 150.0f * Time::DeltaTime();

	if (Input::GetKey(eKeyCode::D))
		pos.x += 150.0f * Time::DeltaTime();


	tr->SetPos(pos);
}

void HighwayMan::combat()
{
}

void HighwayMan::idle()
{
	if (Input::GetKeyDown(eKeyCode::A)
		|| Input::GetKeyDown(eKeyCode::D))
	{
		mState = eHighwayManState::Walk;
		mAnimator->Play(L"highwayman_walk", true);
	}

}
