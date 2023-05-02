#include "EntranceDoor.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"
#include "Animator.h"
#include "Collider.h"
#include "Scene.h"

EntranceDoor::EntranceDoor()
{
}

EntranceDoor::~EntranceDoor()
{
}

void EntranceDoor::Initialize()
{
	tr = GetComponent<Transform>();
	tr->SetPos(Vector2(195.0f, 560.0f));
	tr->SetScale(Vector2{ 0.92f, 1.0f });
	mImage = Resources::Load<Image>(L"Entrance_Door", L"..\\Resources\\Dugeon\\Ruins\\Ruins_Door.bmp");
	
	mAnimator = AddComponent<Animator>();
	mAnimator->CreateAnimation(L"Entrance_Door", mImage, Vector2::Zero, 1, 1, 1, Vector2::Zero, false);

	mAnimator->Play(L"Entrance_Door", true);
	GameObject::Initialize();
}

void EntranceDoor::Update()
{
	GameObject::Update();
}

void EntranceDoor::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void EntranceDoor::Release()
{
	GameObject::Release();
}
