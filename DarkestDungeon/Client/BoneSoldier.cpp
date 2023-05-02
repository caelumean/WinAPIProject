#include "BoneSoldier.h"
#include "Time.h"
#include "SceneManager.h"
#include "Input.h"
#include "Resources.h"
#include "Transform.h"
#include "Animator.h"
#include "Scene.h"
#include "Object.h"

BoneSoldier::BoneSoldier()
{
}

BoneSoldier::~BoneSoldier()
{
}

void BoneSoldier::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetScale(Vector2{ 0.5f, 0.5f });

	//D:\WinAPIProject\DarkestDungeon\Resources\Enemys\Ruins\BoneDefender
	Image* Idle = Resources::Load<Image>(L"BoneSolider_Idle", L"..\\Resources\\Enemys\\Ruins\\BoneSoldier\\BoneSoldier_Idle.bmp");

	mAnimator = AddComponent<Animator>();
	mAnimator->CreateAnimation(L"BoneSolider_Idle", Idle, Vector2::Zero, 12, 1, 12, Vector2::Zero, 0.1f);

	mAnimator->Play(L"BoneSolider_Idle", true);

	mState = eBoneSoldierState::Idle;

	GameObject::Initialize();
}

void BoneSoldier::Update()
{
	GameObject::Update();
}

void BoneSoldier::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void BoneSoldier::Release()
{
	GameObject::Release();
}

void BoneSoldier::idle()
{
}

void BoneSoldier::death()
{
}
