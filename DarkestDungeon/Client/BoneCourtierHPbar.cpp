#include "BoneCourtierHPbar.h"
#include "Time.h"
#include "SceneManager.h"
#include "Input.h"
#include "Resources.h"
#include "Transform.h"
#include "Animator.h"
#include "Scene.h"

BoneCourtierHPbar::BoneCourtierHPbar()
{
}

BoneCourtierHPbar::~BoneCourtierHPbar()
{
}

void BoneCourtierHPbar::Initialize()
{
	tr = GetComponent<Transform>();
	//tr->SetPos(Vector2(580.0f, 620.0f));
	tr->SetScale(Vector2{ 11.0f, 1.0f });
	mImage = Resources::Load<Image>(L"BoneCourtierHPbar", L"..\\Resources\\Heroes\\Health\\health_pip_full.bmp");

	mAnimator = AddComponent<Animator>();
	mAnimator->CreateAnimation(L"BoneCourtierHPbar", mImage, Vector2::Zero, 1, 1, 1, Vector2::Zero, false);

	mAnimator->Play(L"BoneCourtierHPbar", true);
	GameObject::Initialize();
}

void BoneCourtierHPbar::Update()
{
	GameObject::Update();
}

void BoneCourtierHPbar::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void BoneCourtierHPbar::Release()
{
	GameObject::Release();
}
