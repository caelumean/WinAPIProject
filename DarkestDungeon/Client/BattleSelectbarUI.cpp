#include "BattleSelectbarUI.h"
#include "Time.h"
#include "SceneManager.h"
#include "Input.h"
#include "Resources.h"
#include "Transform.h"
#include "Animator.h"
#include "Scene.h"
#include "Time.h"
#include "Object.h"

BattleSelectbarUI::BattleSelectbarUI()
	:mTime(0.0f)
{
}

BattleSelectbarUI::~BattleSelectbarUI()
{
}

void BattleSelectbarUI::Initialize()
{
	tr = GetComponent<Transform>();
	tr->SetScale(Vector2{ 0.5f, 0.6f });
	//D:\WinAPIProject\DarkestDungeon\Resources\Dugeon\UI
	mImage = Resources::Load<Image>(L"BattleSelectBar", L"..\\Resources\\Dugeon\\UI\\select.bmp");

	mAnimator = AddComponent<Animator>();
	mAnimator->CreateAnimation(L"BattleSelectBar", mImage, Vector2::Zero, 3, 1, 3, Vector2::Zero, 0.8f);

	mAnimator->Play(L"BattleSelectBar", true);
	GameObject::Initialize();
}

void BattleSelectbarUI::Update()
{
	GameObject::Update();

	mTime += Time::DeltaTime();

	// 시간이 지나면 삭제
	if (mTime > 2.0f)
	{
		object::Destory(this);
	}

}

void BattleSelectbarUI::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void BattleSelectbarUI::Release()
{
	GameObject::Release();
}

