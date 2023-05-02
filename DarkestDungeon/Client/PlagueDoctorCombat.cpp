#include "PlagueDoctorCombat.h"
#include "Time.h"
#include "SceneManager.h"
#include "Input.h"
#include "Resources.h"
#include "Transform.h"
#include "Animator.h"
#include "Scene.h"
#include "Object.h"

PlagueDoctorCombat::PlagueDoctorCombat()
{
}

PlagueDoctorCombat::~PlagueDoctorCombat()
{
}

void PlagueDoctorCombat::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(430.0f, 860.0f));
	tr->SetScale(Vector2{ 0.5f, 0.5f });

	Image* Combat = Resources::Load<Image>(L"plaguedoctor_Combat", L"..\\Resources\\Heroes\\plague_doctor\\plague_doctor_Combat.bmp");

	mAnimator = AddComponent<Animator>();
	mAnimator->CreateAnimation(L"plaguedoctor_Combat", Combat, Vector2::Zero, 12, 1, 12, Vector2::Zero, 0.1f);

	mAnimator->Play(L"plaguedoctor_Combat", true);

	mState = ePlagueDoctorState::Combat;

	GameObject::Initialize();
}

void PlagueDoctorCombat::Update()
{
	GameObject::Update();
}

void PlagueDoctorCombat::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void PlagueDoctorCombat::Release()
{
	GameObject::Release();
}

void PlagueDoctorCombat::death()
{
}
