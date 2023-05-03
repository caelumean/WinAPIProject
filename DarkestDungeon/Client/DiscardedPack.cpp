#include "DiscardedPack.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"
#include "Animator.h"
#include "Collider.h"
#include "Scene.h"
#include "Object.h"

DiscardedPack::DiscardedPack()
{
}

DiscardedPack::~DiscardedPack()
{
}

void DiscardedPack::Initialize()
{
	tr = GetComponent<Transform>();
	tr->SetPos(Vector2(2500.0f, 600.0f));
	tr->SetScale(Vector2{ 0.92f, 1.0f });
	//D:\WinAPIProject\DarkestDungeon\Resources\Dugeon\dungeonOBJ
	mImage = Resources::Load<Image>(L"Discarded_Pack", L"..\\Resources\\Dugeon\\dungeonOBJ\\Discarded_Pack1.bmp");

	mAnimator = AddComponent<Animator>();
	mAnimator->CreateAnimation(L"Discarded_Pack", mImage, Vector2::Zero, 1, 1, 1, Vector2::Zero, false);

	mAnimator->Play(L"Discarded_Pack", true);

	GameObject::Initialize();
}

void DiscardedPack::Update()
{
	GameObject::Update();
}

void DiscardedPack::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void DiscardedPack::Release()
{
	GameObject::Release();
}
