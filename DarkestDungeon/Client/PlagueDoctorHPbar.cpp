#include "PlagueDoctorHPbar.h"
#include "Time.h"
#include "SceneManager.h"
#include "Input.h"
#include "Resources.h"
#include "Transform.h"
#include "Animator.h"
#include "Scene.h"


PlagueDoctorHPbar::PlagueDoctorHPbar()
{
}

PlagueDoctorHPbar::~PlagueDoctorHPbar()
{
}

void PlagueDoctorHPbar::Initialize()
{
	tr = GetComponent<Transform>();
	//tr->SetPos(Vector2(580.0f, 620.0f));
	tr->SetScale(Vector2{ 11.0f, 1.0f });
	mImage = Resources::Load<Image>(L"PlagueDoctorHP", L"..\\Resources\\Heroes\\Health\\health_pip_full.bmp");

	mAnimator = AddComponent<Animator>();
	mAnimator->CreateAnimation(L"PlagueDoctorHP", mImage, Vector2::Zero, 1, 1, 1, Vector2::Zero, false);

	mAnimator->Play(L"PlagueDoctorHP", true);
	GameObject::Initialize();
}

void PlagueDoctorHPbar::Update()
{
	GameObject::Update();

	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	if (Input::GetKey(eKeyCode::A))
		pos.x -= 200.0f * Time::DeltaTime();

	if (Input::GetKey(eKeyCode::D))
		pos.x += 200.0f * Time::DeltaTime();


	tr->SetPos(pos);
}

void PlagueDoctorHPbar::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void PlagueDoctorHPbar::Release()
{
	GameObject::Release();
}
