#include "StackofBooks.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"
#include "Animator.h"
#include "Collider.h"
#include "Scene.h"
#include "Object.h"

StackofBooks::StackofBooks()
{
}

StackofBooks::~StackofBooks()
{
}

void StackofBooks::Initialize()
{
	tr = GetComponent<Transform>();
	tr->SetPos(Vector2(1500.0f, 500.0f));
	tr->SetScale(Vector2{ 1.5f, 1.8f });
	mImage = Resources::Load<Image>(L"Stack_of_Books", L"..\\Resources\\Dugeon\\dungeonOBJ\\Stack_of_Books1.bmp");

	mAnimator = AddComponent<Animator>();
	mAnimator->CreateAnimation(L"Stack_of_Books", mImage, Vector2::Zero, 1, 1, 1, Vector2::Zero, false);

	mAnimator->Play(L"Stack_of_Books", true);

	GameObject::Initialize();
}

void StackofBooks::Update()
{
	GameObject::Update();
}

void StackofBooks::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void StackofBooks::Release()
{
	GameObject::Release();
}
