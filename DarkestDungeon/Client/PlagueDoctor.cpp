#include "PlagueDoctor.h"
#include "Time.h"
#include "SceneManager.h"
#include "Input.h"
#include "Resources.h"
#include "Transform.h"
#include "Animator.h"
#include "Scene.h"
#include "Object.h"

PlagueDoctor::PlagueDoctor()
{
}

PlagueDoctor::~PlagueDoctor()
{
}

void PlagueDoctor::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(430.0f, 860.0f));
	tr->SetScale(Vector2{ 0.5f, 0.5f });

	//D:\WinAPIProject\DarkestDungeon\Resources\Heroes\plague_doctor
	Image* Idle = Resources::Load<Image>(L"plaguedoctor_Idle", L"..\\Resources\\Heroes\\plague_doctor\\plague_doctor_Idle.bmp");
	Image* Move = Resources::Load<Image>(L"plaguedoctor_Move", L"..\\Resources\\Heroes\\plague_doctor\\plague_doctor_Walk.bmp");

	mAnimator = AddComponent<Animator>();
	mAnimator->CreateAnimation(L"plaguedoctor_Idle", Idle, Vector2::Zero, 12, 1, 12, Vector2::Zero, 0.1f);
	mAnimator->CreateAnimation(L"plaguedoctor_Move", Move, Vector2::Zero, 12, 1, 12, Vector2::Zero, 0.08f);

	mAnimator->Play(L"plaguedoctor_Idle", true);

	mState = ePlagueDoctorState::Idle;

	GameObject::Initialize();
}

void PlagueDoctor::Update()
{
	GameObject::Update();

	switch (mState)
	{
	case PlagueDoctor::ePlagueDoctorState::Move:
		move();
		break;
	case PlagueDoctor::ePlagueDoctorState::Combat:
		combat();
		break;
	case PlagueDoctor::ePlagueDoctorState::Idle:
		idle();
		break;
	default:
		break;
	}
}

void PlagueDoctor::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void PlagueDoctor::Release()
{
	GameObject::Release();
}

void PlagueDoctor::move()
{
	if (Input::GetKeyUp(eKeyCode::A)
		|| Input::GetKeyUp(eKeyCode::D))
	{
		mState = ePlagueDoctorState::Idle;
		mAnimator->Play(L"plaguedoctor_Idle", true);
	}

	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();


	if (Input::GetKey(eKeyCode::A))
		pos.x -= 200.0f * Time::DeltaTime();

	if (Input::GetKey(eKeyCode::D))
		pos.x += 200.0f * Time::DeltaTime();


	tr->SetPos(pos);
}

void PlagueDoctor::idle()
{
	if (Input::GetKeyDown(eKeyCode::A)
		|| Input::GetKeyDown(eKeyCode::D))
	{
		mState = ePlagueDoctorState::Move;
		mAnimator->Play(L"plaguedoctor_Move", true);
	}
}

void PlagueDoctor::combat()
{
}

void PlagueDoctor::death()
{
}
