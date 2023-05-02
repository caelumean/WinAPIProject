#include "HighwayManCombat.h"
#include "Time.h"
#include "SceneManager.h"
#include "Input.h"
#include "Resources.h"
#include "Transform.h"
#include "Animator.h"
#include "Collider.h"
#include "Scene.h"
#include "Object.h"

HighwayManCombat::HighwayManCombat()
{
}

HighwayManCombat::~HighwayManCombat()
{
}

void HighwayManCombat::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(585.0f, 880.0f));
	tr->SetScale(Vector2{ 0.5f, 0.5f });

	//D:\WinAPIProject\DarkestDungeon\Resources\Heroes\highwayman
	Image* Combat = Resources::Load<Image>(L"highwayman_Combat", L"..\\Resources\\Heroes\\highwayman\\highwayMan_Combat.bmp");
	mAnimator = AddComponent<Animator>();
	mAnimator->CreateAnimation(L"highwayman_Combat", Combat, Vector2::Zero, 12, 1, 12, Vector2::Zero, 0.1f);

	mAnimator->Play(L"highwayman_Combat", true);

	mState = eCrusaderState::Combat;
	GameObject::Initialize();
}

void HighwayManCombat::Update()
{
	GameObject::Update();
}

void HighwayManCombat::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void HighwayManCombat::Release()
{
	GameObject::Release();
}

void HighwayManCombat::death()
{
}
