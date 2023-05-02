#include "BoneCourtier.h"
#include "Time.h"
#include "SceneManager.h"
#include "Input.h"
#include "Resources.h"
#include "Transform.h"
#include "Animator.h"
#include "Scene.h"
#include "Object.h"

BoneCourtier::BoneCourtier()
{
}

BoneCourtier::~BoneCourtier()
{
}

void BoneCourtier::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetScale(Vector2{ 0.5f, 0.5f });

	//D:\WinAPIProject\DarkestDungeon\Resources\Enemys\Ruins\BoneDefender
	Image* Idle = Resources::Load<Image>(L"BoneCourtier_Idle", L"..\\Resources\\Enemys\\Ruins\\BoneCourtier\\BoneCourtier_Idle.bmp");

	mAnimator = AddComponent<Animator>();
	mAnimator->CreateAnimation(L"BoneCourtier_Idle", Idle, Vector2::Zero, 12, 1, 12, Vector2::Zero, 0.1f);

	mAnimator->Play(L"BoneCourtier_Idle", true);

	mState = eBoneCourtierState::Idle;

	GameObject::Initialize();
}

void BoneCourtier::Update()
{
	GameObject::Update();
}

void BoneCourtier::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void BoneCourtier::Release()
{
	GameObject::Release();
}

void BoneCourtier::idle()
{
}

void BoneCourtier::death()
{
}
