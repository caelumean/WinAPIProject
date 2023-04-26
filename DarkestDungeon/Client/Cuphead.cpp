#include "Cuphead.h"
// ���� ��ü�� �����̴µ� ��ŸŸ���� �����;��Ѵ�.
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

	// ���� ��η� ���� ��Ȯ�� �� �ش���ġ�� ����־�� �ȴ�.
	// �� ��ũ��Ʈ ���� �������� �ϴ� ��� ��η� ����Ѵ�.
	// ..\\ �ϳ� ���� �ö󰡴� ��
	Image* mImage = Resources::Load<Image>(L"Cuphead", L"..\\Resources\\Cuphead_Stage.bmp");
	mAnimator = AddComponent<Animator>();
	mAnimator->CreateAnimation(L"FowardRun", mImage, Vector2::Zero, 16, 8, 16, Vector2::Zero, 0.1);
	mAnimator->CreateAnimation(L"FowardRight", mImage, Vector2(0.0f, 113.0f), 16, 8, 15, Vector2::Zero, 0.1);
	mAnimator->CreateAnimation(L"Idle", mImage, Vector2(0.0f, 113.0f * 5), 16, 8, 9, Vector2(-50.0f, -50.0f), 0.1);
	mAnimator->CreateAnimations(L"..\\Resources\\Chalise\\Idle", Vector2::Zero, 0.1f);
	mAnimator->CreateAnimations(L"..\\Resources\\Chalise\\Aim\\Straight", Vector2::Zero, 0.1f);

	mAnimator->Play(L"ChaliseIdle", true);

	//Collider�߰�
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

// ���⼭ other�� monster�̱� ������
// collider�浹�� �ϸ� monster ���º�ȭ�� ���� �� �ִ�
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

	// �������� �׳� �ٲٴ°� �ƴ϶� ������ٵ� �߰��ؼ� �Ѵ�.
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
	//	// ������� �����ͼ�
	//	Scene* curScene = SceneManager::GetActiveScene();
	//	// �Ѿ��� �����ϰ�
	//	BaseBullet* bullet = new BaseBullet();
	//	// �Ѿ��� ��ġ�� �÷��̾� ��ġ�� ����
	//	bullet->GetComponent<Transform>()->SetPos(tr->GetPos());
	//	// �׸��� ���� ���� ���ӿ�����Ʈ �Ѿ��� �߰����ش�.
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
