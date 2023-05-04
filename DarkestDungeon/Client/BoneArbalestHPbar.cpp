#include "BoneArbalestHPbar.h"
#include "Time.h"
#include "SceneManager.h"
#include "Input.h"
#include "Resources.h"
#include "Transform.h"
#include "Animator.h"
#include "Scene.h"

BoneArbalestHPbar::BoneArbalestHPbar()
{
}

BoneArbalestHPbar::~BoneArbalestHPbar()
{
}

void BoneArbalestHPbar::Initialize()
{
	tr = GetComponent<Transform>();
	//tr->SetPos(Vector2(580.0f, 620.0f));
	tr->SetScale(Vector2{ 11.0f, 1.0f });
	mImage = Resources::Load<Image>(L"BoneArbalestHPbar", L"..\\Resources\\Heroes\\Health\\health_pip_full.bmp");

	mAnimator = AddComponent<Animator>();
	mAnimator->CreateAnimation(L"BoneArbalestHPbar", mImage, Vector2::Zero, 1, 1, 1, Vector2::Zero, false);

	mAnimator->Play(L"BoneArbalestHPbar", true);
	GameObject::Initialize();
}

void BoneArbalestHPbar::Update()
{
	GameObject::Update();
}

void BoneArbalestHPbar::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void BoneArbalestHPbar::Release()
{
	GameObject::Release();
}
