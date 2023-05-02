#include "CrusaderCombat.h"
#include "Time.h"
#include "SceneManager.h"
#include "Input.h"
#include "Resources.h"
#include "Transform.h"
#include "Animator.h"
#include "Collider.h"
#include "Scene.h"
#include "Object.h"

CrusaderCombat::CrusaderCombat()
	:Hp(33)
	,Dodge(5)
	,Speed(1)
	,MinDamage(6)
	,MaxDamage(12)

{

}

CrusaderCombat::~CrusaderCombat()
{
}

void CrusaderCombat::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(720.0f, 850.0f));
	tr->SetScale(Vector2{ 0.5f, 0.58f });

	Image* Combat = Resources::Load<Image>(L"crusader_Combat", L"..\\Resources\\Heroes\\crusader\\crusader_Combat.bmp");
	mAnimator = AddComponent<Animator>();
	mAnimator->CreateAnimation(L"crusader_Combat", Combat, Vector2::Zero, 12, 1, 12, Vector2::Zero, 0.1f);

	mAnimator->Play(L"crusader_Combat", true);

	mState = eCrusaderState::Combat;
	GameObject::Initialize();
}

void CrusaderCombat::Update()
{
	GameObject::Update();

	if (Hp <= 0)
	{
		mState = eCrusaderState::Death;
	}
	switch (mState)
	{
	case CrusaderCombat::eCrusaderState::Combat:
		break;
	case CrusaderCombat::eCrusaderState::Death:
		death();
		break;
	default:
		break;
	}
}

void CrusaderCombat::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void CrusaderCombat::Release()
{
	GameObject::Release();
}

void CrusaderCombat::death()
{
	object::Destory(this);
}
