#include "BattleDoor.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"
#include "Animator.h"
#include "Collider.h"
#include "Scene.h"
#include "Object.h"

BattleDoor::BattleDoor()
{
}

BattleDoor::~BattleDoor()
{
}

void BattleDoor::Initialize()
{
	tr = GetComponent<Transform>();
	tr->SetPos(Vector2(3436.0f, 560.0f));
	tr->SetScale(Vector2{ 0.92f, 1.0f });
	mImage = Resources::Load<Image>(L"Battle_Door", L"..\\Resources\\Dugeon\\Ruins\\Ruins_Door.bmp");

	mAnimator = AddComponent<Animator>();
	mAnimator->CreateAnimation(L"Battle_Door", mImage, Vector2::Zero, 1, 1, 1, Vector2::Zero, false);

	mAnimator->Play(L"Battle_Door", true);

	Collider* collider = AddComponent<Collider>();
	collider->SetCenter(Vector2(-100.0f, -350.0f));
	collider->SetSize(Vector2(200.0f, 300.0f));

	GameObject::Initialize();
}

void BattleDoor::Update()
{
	GameObject::Update();
}

void BattleDoor::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void BattleDoor::Release()
{
	GameObject::Release();
}
