#include "CrusaderHPbar.h"
#include "Time.h"
#include "SceneManager.h"
#include "Input.h"
#include "Resources.h"
#include "Transform.h"
#include "Animator.h"
#include "Collider.h"
#include "Scene.h"

CrusaderHPbar::CrusaderHPbar()
{
}

CrusaderHPbar::~CrusaderHPbar()
{
}

void CrusaderHPbar::Initialize()
{
	tr = GetComponent<Transform>();
	tr->SetPos(Vector2(580.0f, 620.0f));
	tr->SetScale(Vector2{ 11.0f, 1.0f });
	mImage = Resources::Load<Image>(L"CrusaderHP_3", L"..\\Resources\\Heroes\\Health\\health_pip_full.bmp");

	mAnimator = AddComponent<Animator>();
	mAnimator->CreateAnimation(L"CrusaderHP_3", mImage, Vector2::Zero, 1, 1, 1, Vector2::Zero, false);

	mAnimator->Play(L"CrusaderHP_3", true);
	GameObject::Initialize();
}

void CrusaderHPbar::Update()
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

void CrusaderHPbar::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void CrusaderHPbar::Release()
{
	GameObject::Release();
}
