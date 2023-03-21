#include "PlagueDoctor.h"
#include "Time.h"
#include "SceneManager.h"
#include "Input.h"
#include "yaResources.h"
#include "Transform.h"
#include "Animator.h"
#include "Collider.h"
#include "Scene.h"

PlagueDoctor::PlagueDoctor()
{
}

PlagueDoctor::~PlagueDoctor()
{
}

void PlagueDoctor::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(290.0f, 935.0f));
	tr->SetScale(Vector2{ 0.6f, 0.5f });

	//D:\WinAPIProject\DarkestDungeon\Resources\Heroes\plague_doctor
	Image* mImage = Resources::Load<Image>(L"plaguedoctor_Idle", L"..\\Resources\\Heroes\\plague_doctor\\plague_doctor_Idle.bmp");
	Image* mImage2 = Resources::Load<Image>(L"plaguedoctor_walk", L"..\\Resources\\Heroes\\plague_doctor\\plague_doctor_Walk.bmp");
	Image* mImage3 = Resources::Load<Image>(L"plaguedoctor_combat", L"..\\Resources\\Heroes\\plague_doctor\\plague_doctor_Combat.bmp");

	mAnimator = AddComponent<Animator>();
	mAnimator->CreateAnimation(L"plaguedoctor_Idle", mImage, Vector2::Zero, 12, 1, 12, Vector2::Zero, 0.1f);
	mAnimator->CreateAnimation(L"plaguedoctor_walk", mImage2, Vector2::Zero, 12, 1, 12, Vector2::Zero, 0.08f);
	mAnimator->CreateAnimation(L"plaguedoctor_combat", mImage3, Vector2::Zero, 12, 1, 12, Vector2::Zero, 0.1f);

	mAnimator->Play(L"plaguedoctor_Idle", true);
	Collider* collider = AddComponent<Collider>();
	collider->SetCenter(Vector2(-150.0f, -535.0f));

	mState = ePlagueDoctorState::Idle;

	GameObject::Initialize();
}

void PlagueDoctor::Update()
{
	GameObject::Update();

	switch (mState)
	{
	case PlagueDoctor::ePlagueDoctorState::Walk:
		walk();
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

void PlagueDoctor::walk()
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
		pos.x -= 150.0f * Time::DeltaTime();

	if (Input::GetKey(eKeyCode::D))
		pos.x += 150.0f * Time::DeltaTime();


	tr->SetPos(pos);
}

void PlagueDoctor::combat()
{
}

void PlagueDoctor::idle()
{
	if (Input::GetKeyDown(eKeyCode::A)
		|| Input::GetKeyDown(eKeyCode::D))
	{
		mState = ePlagueDoctorState::Walk;
		mAnimator->Play(L"plaguedoctor_walk", true);
	}
}
