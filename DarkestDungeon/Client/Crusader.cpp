#include "Crusader.h"
#include "Time.h"
#include "SceneManager.h"
#include "Input.h"
#include "Resources.h"
#include "Transform.h"
#include "Animator.h"
#include "Collider.h"
#include "Scene.h"
#include "Object.h"
#include "Sound.h"


Crusader::Crusader()
{
}

Crusader::~Crusader()
{
}

void Crusader::Initialize()
{
	//D:\WinAPIProject\DarkestDungeon\Resources\Sound\SoundEffect\Footstep
	//MoveBGM = Resources::Load<Sound>(L"Combat", L"..\\Resources\\Sound\\SoundEffect\\Footstep\\party_foot_grass.wav");
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(720.0f, 900.0f));
	tr->SetScale(Vector2{ 0.5f, 0.5f });

	Image* Idle = Resources::Load<Image>(L"crusader_Idle", L"..\\Resources\\Heroes\\crusader\\crusader_Idle.bmp");
	Image* Move = Resources::Load<Image>(L"crusader_Move", L"..\\Resources\\Heroes\\crusader\\crusader_Walk.bmp");
	mAnimator = AddComponent<Animator>();
	mAnimator->CreateAnimation(L"crusader_Idle", Idle, Vector2::Zero, 12, 1, 12, Vector2::Zero, 0.1f);
	mAnimator->CreateAnimation(L"crusader_Move", Move, Vector2::Zero, 12, 1, 12, Vector2::Zero, 0.08f);


	mAnimator->Play(L"crusader_Idle", true);

	Collider* collider = AddComponent<Collider>();
	collider->SetCenter(Vector2(-170.0f, -550.0f));
	collider->SetSize(Vector2(150.0f, 250.0f));

	mState = eCrusaderState::Idle;

	GameObject::Initialize();
}

void Crusader::Update()
{
	GameObject::Update();

	switch (mState)
	{
	case Crusader::eCrusaderState::Move:
		move();
		break;
	case Crusader::eCrusaderState::Idle:
		idle();
		break;
	default:
		break;
	}
}

void Crusader::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void Crusader::Release()
{
	GameObject::Release();
}

void Crusader::OnCollisionEnter(Collider* other)
{
	//if (other->GetOwner()->GetLayerType() == eLayerType::BattleRoomDoor)
	//{
	//	if (Input::GetKeyState(eKeyCode::W) == eKeyState::Down)
	//	{
	//		SceneManager::LoadScene(eSceneType::RuinsBattle);
	//		
	//	}
	//}
}

void Crusader::OnCollisionStay(Collider* other)
{
}

void Crusader::OnCollisionExit(Collider* other)
{
}

void Crusader::move()
{
	//MoveBGM->Play(true);

	if (Input::GetKeyUp(eKeyCode::A)
		|| Input::GetKeyUp(eKeyCode::D))
	{
		mState = eCrusaderState::Idle;
		mAnimator->Play(L"crusader_Idle", true);
	}

	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	if (Input::GetKey(eKeyCode::A))
		pos.x -= 200.0f * Time::DeltaTime();

	if (Input::GetKey(eKeyCode::D))
		pos.x += 200.0f * Time::DeltaTime();


	tr->SetPos(pos);
}

void Crusader::idle()
{
	//MoveBGM->Stop(true);
	if (Input::GetKeyDown(eKeyCode::A)
		|| Input::GetKeyDown(eKeyCode::D))
	{
		mState = eCrusaderState::Move;
		mAnimator->Play(L"crusader_Move", true);
	}
}

void Crusader::death()
{
}
