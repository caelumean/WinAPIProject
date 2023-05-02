#include "BoneArbalest.h"
#include "Time.h"
#include "SceneManager.h"
#include "Input.h"
#include "Resources.h"
#include "Transform.h"
#include "Animator.h"
#include "Scene.h"
#include "Object.h"

BoneArbalest::BoneArbalest()
{
}

BoneArbalest::~BoneArbalest()
{
}

void BoneArbalest::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetScale(Vector2{ 0.85f, 0.85f });

	//D:\WinAPIProject\DarkestDungeon\Resources\Enemys\Ruins\BoneDefender
	Image* Idle = Resources::Load<Image>(L"BoneArbalest_Idle", L"..\\Resources\\Enemys\\Ruins\\BoneArbalest\\BoneArbalest_Idle.bmp");

	mAnimator = AddComponent<Animator>();
	mAnimator->CreateAnimation(L"BoneArbalest_Idle", Idle, Vector2::Zero, 12, 1, 12, Vector2::Zero, 0.1f);

	mAnimator->Play(L"BoneArbalest_Idle", true);

	mState = eBoneArbalestState::Idle;

	GameObject::Initialize();
}

void BoneArbalest::Update()
{
	GameObject::Update();
}

void BoneArbalest::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void BoneArbalest::Release()
{
	GameObject::Release();
}

void BoneArbalest::idle()
{
}

void BoneArbalest::death()
{
}
