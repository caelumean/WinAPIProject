#include "BoneDefenderHPbar.h"
#include "Time.h"
#include "SceneManager.h"
#include "Input.h"
#include "Resources.h"
#include "Transform.h"
#include "Animator.h"
#include "Scene.h"

BoneDefenderHPbar::BoneDefenderHPbar()
{
}

BoneDefenderHPbar::~BoneDefenderHPbar()
{
}

void BoneDefenderHPbar::Initialize()
{
	tr = GetComponent<Transform>();
	//tr->SetPos(Vector2(580.0f, 620.0f));
	tr->SetScale(Vector2{ 11.0f, 1.0f });
	mImage = Resources::Load<Image>(L"BoneDefenderHPbar", L"..\\Resources\\Heroes\\Health\\health_pip_full.bmp");

	mAnimator = AddComponent<Animator>();
	mAnimator->CreateAnimation(L"BoneDefenderHPbar", mImage, Vector2::Zero, 1, 1, 1, Vector2::Zero, false);

	mAnimator->Play(L"BoneDefenderHPbar", true);
	GameObject::Initialize();
}

void BoneDefenderHPbar::Update()
{
	GameObject::Update();
}

void BoneDefenderHPbar::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void BoneDefenderHPbar::Release()
{
	GameObject::Release();
}
