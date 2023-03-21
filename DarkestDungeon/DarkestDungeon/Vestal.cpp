#include "Vestal.h"
#include "Time.h"
#include "SceneManager.h"
#include "Input.h"
#include "yaResources.h"
#include "Transform.h"
#include "Animator.h"
#include "Collider.h"
#include "Scene.h"

Vestal::Vestal()
{
}

Vestal::~Vestal()
{
}

void Vestal::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(460.0f, 938.0f));
	tr->SetScale(Vector2{ 0.6f, 0.5f });

	//D:\WinAPIProject\DarkestDungeon\Resources\Heroes\vestal
	Image* mImage = Resources::Load<Image>(L"vestal_Idle", L"..\\Resources\\Heroes\\vestal\\Vestal_Idle.bmp");
	Image* mImage2 = Resources::Load<Image>(L"vestal_walk", L"..\\Resources\\Heroes\\vestal\\Vestal_Walk.bmp");
	Image* mImage3 = Resources::Load<Image>(L"vestal_combat", L"..\\Resources\\Heroes\\vestal\\Vestal_Combat.bmp");

	mAnimator = AddComponent<Animator>();
	mAnimator->CreateAnimation(L"vestal_Idle", mImage, Vector2::Zero, 12, 1, 12, Vector2::Zero, 0.1f);
	mAnimator->CreateAnimation(L"vestal_walk", mImage2, Vector2::Zero, 12, 1, 12, Vector2::Zero, 0.08f);
	mAnimator->CreateAnimation(L"vestal_combat", mImage3, Vector2::Zero, 12, 1, 12, Vector2::Zero, 0.1f);

	mAnimator->Play(L"vestal_Idle", true);
	Collider* collider = AddComponent<Collider>();
	collider->SetCenter(Vector2(-150.0f, -538.0f));

	mState = eVestalState::Idle;

	GameObject::Initialize();
}

void Vestal::Update()
{
	GameObject::Update();

	switch (mState)
	{
	case Vestal::eVestalState::Walk:
		walk();
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

void Vestal::walk()
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
		pos.x -= 150.0f * Time::DeltaTime();

	if (Input::GetKey(eKeyCode::D))
		pos.x += 150.0f * Time::DeltaTime();


	tr->SetPos(pos);
}

void Vestal::combat()
{
}

void Vestal::idle()
{
	if (Input::GetKeyDown(eKeyCode::A)
		|| Input::GetKeyDown(eKeyCode::D))
	{
		mState = eVestalState::Walk;
		mAnimator->Play(L"vestal_walk", true);
	}
}
