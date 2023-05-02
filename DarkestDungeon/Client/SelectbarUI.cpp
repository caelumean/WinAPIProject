#include "SelectbarUI.h"
#include "Time.h"
#include "SceneManager.h"
#include "Input.h"
#include "Resources.h"
#include "Transform.h"
#include "Animator.h"
#include "Scene.h"

SelectbarUI::SelectbarUI()
{
}

SelectbarUI::~SelectbarUI()
{
}

void SelectbarUI::Initialize()
{
	tr = GetComponent<Transform>();
	tr->SetScale(Vector2{ 0.5f, 0.6f });
	//D:\WinAPIProject\DarkestDungeon\Resources\Dugeon\UI
	mImage = Resources::Load<Image>(L"SelectBar", L"..\\Resources\\Dugeon\\UI\\select.bmp");

	mAnimator = AddComponent<Animator>();
	mAnimator->CreateAnimation(L"SelectBar", mImage, Vector2::Zero, 3, 1, 3, Vector2::Zero, 0.8f);

	mAnimator->Play(L"SelectBar", true);
	GameObject::Initialize();
}

void SelectbarUI::Update()
{
	GameObject::Update();

	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	if (Input::GetKey(eKeyCode::A))
		pos.x -= 200.0f * Time::DeltaTime();

	if (Input::GetKey(eKeyCode::D))
		pos.x += 200.0f * Time::DeltaTime();


	tr->SetPos(pos);
}

void SelectbarUI::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void SelectbarUI::Release()
{
	GameObject::Release();
}
