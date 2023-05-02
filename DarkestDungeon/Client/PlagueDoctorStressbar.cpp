#include "PlagueDoctorStressbar.h"
#include "Time.h"
#include "SceneManager.h"
#include "Input.h"
#include "Resources.h"
#include "Transform.h"
#include "Animator.h"
#include "Scene.h"

PlagueDoctorStressbar::PlagueDoctorStressbar()
{
}

PlagueDoctorStressbar::~PlagueDoctorStressbar()
{
}

void PlagueDoctorStressbar::Initialize()
{
	tr = GetComponent<Transform>();

	tr->SetScale(Vector2{ 1.1f, 1.0f });
	mImage = Resources::Load<Image>(L"PlagueDoctorStress", L"..\\Resources\\Heroes\\Stress\\stress.bmp");

	mAnimator = AddComponent<Animator>();
	mAnimator->CreateAnimation(L"PlagueDoctorStress", mImage, Vector2::Zero, 1, 1, 1, Vector2::Zero, false);

	mAnimator->Play(L"PlagueDoctorStress", true);
	GameObject::Initialize();
}

void PlagueDoctorStressbar::Update()
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

void PlagueDoctorStressbar::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void PlagueDoctorStressbar::Release()
{
	GameObject::Release();
}
