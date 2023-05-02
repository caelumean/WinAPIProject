#include "VestalHPbar.h"
#include "Time.h"
#include "SceneManager.h"
#include "Input.h"
#include "Resources.h"
#include "Transform.h"
#include "Animator.h"
#include "Scene.h"

VestalHPbar::VestalHPbar()
{
}

VestalHPbar::~VestalHPbar()
{
}

void VestalHPbar::Initialize()
{
	tr = GetComponent<Transform>();
	//tr->SetPos(Vector2(580.0f, 620.0f));
	tr->SetScale(Vector2{ 11.0f, 1.0f });
	mImage = Resources::Load<Image>(L"VestalHP", L"..\\Resources\\Heroes\\Health\\health_pip_full.bmp");

	mAnimator = AddComponent<Animator>();
	mAnimator->CreateAnimation(L"VestalHP", mImage, Vector2::Zero, 1, 1, 1, Vector2::Zero, false);

	mAnimator->Play(L"VestalHP", true);
	GameObject::Initialize();
}

void VestalHPbar::Update()
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

void VestalHPbar::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void VestalHPbar::Release()
{
	GameObject::Release();
}
