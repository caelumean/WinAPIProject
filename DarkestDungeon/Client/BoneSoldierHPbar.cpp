#include "BoneSoldierHPbar.h"
#include "Time.h"
#include "SceneManager.h"
#include "Input.h"
#include "Resources.h"
#include "Transform.h"
#include "Animator.h"
#include "Scene.h"

BoneSoldierHPbar::BoneSoldierHPbar()
{
}

BoneSoldierHPbar::~BoneSoldierHPbar()
{
}

void BoneSoldierHPbar::Initialize()
{
	tr = GetComponent<Transform>();
	//tr->SetPos(Vector2(580.0f, 620.0f));
	tr->SetScale(Vector2{ 11.0f, 1.0f });
	mImage = Resources::Load<Image>(L"BoneSoldierHPbar", L"..\\Resources\\Heroes\\Health\\health_pip_full.bmp");

	mAnimator = AddComponent<Animator>();
	mAnimator->CreateAnimation(L"BoneSoldierHPbar", mImage, Vector2::Zero, 1, 1, 1, Vector2::Zero, false);

	mAnimator->Play(L"BoneSoldierHPbar", true);
	GameObject::Initialize();
}

void BoneSoldierHPbar::Update()
{
	GameObject::Update();
}

void BoneSoldierHPbar::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void BoneSoldierHPbar::Release()
{
	GameObject::Release();
}
