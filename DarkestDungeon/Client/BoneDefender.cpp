#include "BoneDefender.h"
#include "Time.h"
#include "SceneManager.h"
#include "Input.h"
#include "Resources.h"
#include "Transform.h"
#include "Animator.h"
#include "Scene.h"
#include "Object.h"


BoneDefender::BoneDefender()
{
}

BoneDefender::~BoneDefender()
{
}

void BoneDefender::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetScale(Vector2{ 0.5f, 0.5f });

	//D:\WinAPIProject\DarkestDungeon\Resources\Enemys\Ruins\BoneDefender
	Image* Idle = Resources::Load<Image>(L"BoneDefender_Idle", L"..\\Resources\\Enemys\\Ruins\\BoneDefender\\BoneDefender_Idle.bmp");
	//Image* Attack = Resources::Load<Image>(L"BoneDefender_Attack", L"..\\Resources\\Enemys\\Ruins\\BoneDefender\\BoneDefender_attack.bmp");
	//Image* Defend = Resources::Load<Image>(L"BoneDefender_Defend", L"..\\Resources\\Enemys\\Ruins\\BoneDefender\\BoneDefender_defend.bmp");

	mAnimator = AddComponent<Animator>();
	mAnimator->CreateAnimation(L"BoneDefender_Idle", Idle, Vector2::Zero, 12, 1, 12, Vector2::Zero, 0.1f);

	mAnimator->Play(L"BoneDefender_Idle", true);

	mState = eBoneDefenderState::Idle;

	GameObject::Initialize();
}

void BoneDefender::Update()
{
	GameObject::Update();

	switch (mState)
	{
	case BoneDefender::eBoneDefenderState::Idle:
		idle();
		break;
	case BoneDefender::eBoneDefenderState::Attack:
		attack();
		break;
	case BoneDefender::eBoneDefenderState::Defend:
		defend();
		break;
	case BoneDefender::eBoneDefenderState::Death:
		death();
		break;
	default:
		break;
	}
}

void BoneDefender::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void BoneDefender::Release()
{
	GameObject::Release();
}

void BoneDefender::idle()
{
}

void BoneDefender::attack()
{
}

void BoneDefender::defend()
{
}

void BoneDefender::death()
{
}
