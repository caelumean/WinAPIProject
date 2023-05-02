#include "CrusaderStressbar.h"
#include "Time.h"
#include "SceneManager.h"
#include "Input.h"
#include "Resources.h"
#include "Transform.h"
#include "Animator.h"
#include "Scene.h"

CrusaderStressbar::CrusaderStressbar()
{
}

CrusaderStressbar::~CrusaderStressbar()
{
}

void CrusaderStressbar::Initialize()
{
	tr = GetComponent<Transform>();
	
	tr->SetScale(Vector2{ 1.1f, 1.0f });
	mImage = Resources::Load<Image>(L"CrusaderStress", L"..\\Resources\\Heroes\\Stress\\stress.bmp");

	mAnimator = AddComponent<Animator>();
	mAnimator->CreateAnimation(L"CrusaderStress", mImage, Vector2::Zero, 1, 1, 1, Vector2::Zero, false);

	mAnimator->Play(L"CrusaderStress", true);
	GameObject::Initialize();
}

void CrusaderStressbar::Update()
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

void CrusaderStressbar::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void CrusaderStressbar::Release()
{
	GameObject::Release();
}
