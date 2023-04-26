#include "Rigidbody.h"
#include "Time.h"
#include "GameObject.h"
#include "Transform.h"

Rigidbody::Rigidbody()
	: Component(eComponentType::Rigidbody)
	, mMass(0.0f)
	, mForce(Vector2::Zero)
	, mAccelation(Vector2::Zero)
	, mVelocity(Vector2::Zero)
{
	mLimitedVelocity.x = 200.0f;
	mLimitedVelocity.y = 1000.0f;
	mbGround = false;
	mGravity = Vector2(0.0f, 800.0f);
	mFriction = 100.0f;
}

Rigidbody::~Rigidbody()
{
}

void Rigidbody::Initialize()
{
}

void Rigidbody::Update()
{
	// F = M * A
	// A = M / F
	mAccelation = mForce / mMass;

	// 속도에 가속도를 더해준다.
	mVelocity += mAccelation * Time::DeltaTime();

	if (mbGround)
	{
		// 땅위에 있을때
		Vector2 gravity = mGravity;
		// 중력이 방향만 가져올거니까 
		// notmalize를 가져온다 길이가 1인 단위벡터
		gravity.Normalize();

		// 내 속도랑 중력을 내적해준다
		float dot = math::Dot(mVelocity, gravity);
		// 내속도 -= 중력*내적
		mVelocity -= gravity * dot;
	}
	// 공중에 있을 때는 아무 의미 없으니까
	else
	{
		// 내 방향에다가 중력*타입한 것을 더해주면 된다.
		mVelocity += mGravity * Time::DeltaTime();
	}

	// 중력가속도 최대 속도 제한
	Vector2 gravity = mGravity;
	gravity.Normalize();
	float dot = math::Dot(mVelocity, gravity);
	gravity = gravity * dot;

	// sideVelocity = 내 속도 - 중력
	// 위아래는 최대 속도가 중력에 영향을 받는다.
	Vector2 sideVelocity = mVelocity - gravity;
	if (mLimitedVelocity.y < gravity.Length())
	{
		gravity.Normalize();
		gravity *= mLimitedVelocity.y;
	}


	// 좌우로는 따로 적용이 된다
	if (mLimitedVelocity.x < sideVelocity.Length())
	{
		sideVelocity.Normalize();
		sideVelocity *= mLimitedVelocity.x;
	}

	// 마찰력 조건 ( 적용된 힘이 없고, 속도가 0이 아님)
	if (!(mVelocity == Vector2::Zero))
	{
		//속도에 반대방향으로 마찰력이 적용된다.
		Vector2 friction = -mVelocity;
		friction = friction.Normalize() * mFriction * mMass * Time::DeltaTime();

		//마찰력으로 인한 속도 감소는 현재 속도보다 큰 경우
		// 마찰력이 더 큰경우 속도는 0
		if (mVelocity.Length() < friction.Length())
		{
			mVelocity = Vector2::Zero;
		}
		// 마찰력이 속도보다 작은 경우
		// 마찰력을 더해주면 된다.
		else
		{
			mVelocity += friction;
		}
	}

	// 속도에 맞게끔 물체를 이동시킨다.
	Transform* tr = GetOwner()->GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	pos = pos + mVelocity * Time::DeltaTime();

	tr->SetPos(pos);
	// 계속 Force가 남아있으면 계속 이동하니까 
	// Force는 다시 초기화 해줘야한다.
	mForce.Clear();
}

void Rigidbody::Render(HDC hdc)
{
}

void Rigidbody::Release()
{
}

void Rigidbody::AddForce(Vector2 force)
{
	mForce += force;
}
