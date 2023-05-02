#include "VestalCombat.h"
#include "Time.h"
#include "SceneManager.h"
#include "Input.h"
#include "Resources.h"
#include "Transform.h"
#include "Animator.h"
#include "Scene.h"
#include "Object.h"

VestalCombat::VestalCombat()
{
}

VestalCombat::~VestalCombat()
{
}

void VestalCombat::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(300.0f, 860.0f));
	tr->SetScale(Vector2{ 0.5f, 0.5f });

	Image* Combat = Resources::Load<Image>(L"vestal_Combat", L"..\\Resources\\Heroes\\vestal\\Vestal_Combat.bmp");

	mAnimator = AddComponent<Animator>();

	mAnimator->CreateAnimation(L"vestal_Combat", Combat, Vector2::Zero, 12, 1, 12, Vector2::Zero, 0.1f);

	mAnimator->Play(L"vestal_Combat", true);

	mState = eVestalState::Combat;

	GameObject::Initialize();
}

void VestalCombat::Update()
{
	GameObject::Update();
}

void VestalCombat::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void VestalCombat::Release()
{
	GameObject::Release();
}

void VestalCombat::death()
{
}
