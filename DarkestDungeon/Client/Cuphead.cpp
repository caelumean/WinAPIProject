#include "Cuphead.h"
// 이제 물체가 움직이는데 델타타임을 가져와야한다.
#include "Time.h"
#include "SceneManager.h"
#include "Input.h"
#include "Resources.h"
#include "Transform.h"
#include "Animator.h"
#include "Collider.h"
#include "Scene.h"
#include "Object.h"

Cuphead::Cuphead()
{
}

Cuphead::~Cuphead()
{
}

void Cuphead::Initialize()
{
	/*Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(400.0f, 400.0f));
	tr->SetScale(Vector2(1.5f, 1.5f));
	*/

	// 절대 경로로 쓰면 정확히 그 해당위치에 깔려있어야 된다.
	// 내 스크립트 파일 기준으로 하는 상대 경로로 써야한다.
	// ..\\ 하나 위로 올라가는 것
	Image* mImage = Resources::Load<Image>(L"Cuphead", L"..\\Resources\\Cuphead_Stage.bmp");
	mAnimator = AddComponent<Animator>();
	mAnimator->CreateAnimation(L"FowardRun", mImage, Vector2::Zero, 16, 8, 16, Vector2::Zero, 0.1);
	mAnimator->CreateAnimation(L"FowardRight", mImage, Vector2(0.0f, 113.0f), 16, 8, 15, Vector2::Zero, 0.1);
	mAnimator->CreateAnimation(L"Idle", mImage, Vector2(0.0f, 113.0f * 5), 16, 8, 9, Vector2(-50.0f, -50.0f), 0.1);
	mAnimator->CreateAnimations(L"..\\Resources\\Chalise\\Idle", Vector2::Zero, 0.1f);
	mAnimator->CreateAnimations(L"..\\Resources\\Chalise\\Aim\\Straight", Vector2::Zero, 0.1f);

	mAnimator->Play(L"ChaliseIdle", true);

	//Collider추가
	Collider* collider = AddComponent<Collider>();
	collider->SetCenter(Vector2(-75.0f, -145.0f));
	collider->SetSize(Vector2(150.0f, 150.0f));

	mState = eCupheadState::Idle;

	GameObject::Initialize();
}

void Cuphead::Update()
{
	GameObject::Update();

	switch (mState)
	{
	case Cuphead::eCupheadState::Move:
		move();
		break;
	case Cuphead::eCupheadState::Shoot:
		shoot();
		break;
	case Cuphead::eCupheadState::Death:
		death();
		break;
	case Cuphead::eCupheadState::Idle:
		idle();
		break;
	default:
		break;
	}
}

void Cuphead::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void Cuphead::Release()
{
	GameObject::Release();
}

// 여기서 other가 monster이기 때문에
// collider충돌을 하면 monster 상태변화를 해줄 수 있다
void Cuphead::OnCollisionEnter(Collider* other)
{
}

void Cuphead::OnCollisionStay(Collider* other)
{
}

void Cuphead::OnCollisionExit(Collider* other)
{
}

void Cuphead::move()
{
	if (Input::GetKeyUp(eKeyCode::A)
		|| Input::GetKeyUp(eKeyCode::D)
		|| Input::GetKeyUp(eKeyCode::S)
		|| Input::GetKeyUp(eKeyCode::W))
	{
		mState = eCupheadState::Idle;
		//mAnimator->Play(L"Idle", true);
	}

	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	// 포지션을 그냥 바꾸는게 아니라 리지드바디를 추가해서 한다.
	if (Input::GetKey(eKeyCode::A))
		pos.x -= 100.0f * Time::DeltaTime();

	if (Input::GetKey(eKeyCode::D))
		pos.x += 100.0f * Time::DeltaTime();

	if (Input::GetKey(eKeyCode::W))
		pos.y -= 100.0f * Time::DeltaTime();

	if (Input::GetKey(eKeyCode::S))
		pos.y += 100.0f * Time::DeltaTime();

	tr->SetPos(pos);
}

void Cuphead::shoot()
{
	Transform* tr = GetComponent<Transform>();

	//if (Input::GetKey(eKeyCode::K))
	//{
	//	object::Instantiate<BaseBullet>(Vector2(400.0f, 400.0f), eLayerType::Bullet);

	//	/*
	//	// 현재씬을 가져와서
	//	Scene* curScene = SceneManager::GetActiveScene();
	//	// 총알을 생성하고
	//	BaseBullet* bullet = new BaseBullet();
	//	// 총알의 위치를 플레이어 위치에 셋팅
	//	bullet->GetComponent<Transform>()->SetPos(tr->GetPos());
	//	// 그리고 현재 씬에 게임오브젝트 총알을 추가해준다.
	//	curScene->AddGameObject(bullet, eLayerType::Bullet);
	//	*/
	//}
}

void Cuphead::death()
{
}

void Cuphead::idle()
{
	if (Input::GetKeyDown(eKeyCode::A)
		|| Input::GetKeyDown(eKeyCode::D)
		|| Input::GetKeyDown(eKeyCode::S)
		|| Input::GetKeyDown(eKeyCode::W))
	{
		mState = eCupheadState::Move;
		//mAnimator->Play(L"FowardRun", true);
	}


	if (Input::GetKeyDown(eKeyCode::K))
	{
		mState = eCupheadState::Shoot;
		mAnimator->Play(L"AimStraight", true);
	}
}
