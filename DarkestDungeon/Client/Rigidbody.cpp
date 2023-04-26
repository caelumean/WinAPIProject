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

	// �ӵ��� ���ӵ��� �����ش�.
	mVelocity += mAccelation * Time::DeltaTime();

	if (mbGround)
	{
		// ������ ������
		Vector2 gravity = mGravity;
		// �߷��� ���⸸ �����ðŴϱ� 
		// notmalize�� �����´� ���̰� 1�� ��������
		gravity.Normalize();

		// �� �ӵ��� �߷��� �������ش�
		float dot = math::Dot(mVelocity, gravity);
		// ���ӵ� -= �߷�*����
		mVelocity -= gravity * dot;
	}
	// ���߿� ���� ���� �ƹ� �ǹ� �����ϱ�
	else
	{
		// �� ���⿡�ٰ� �߷�*Ÿ���� ���� �����ָ� �ȴ�.
		mVelocity += mGravity * Time::DeltaTime();
	}

	// �߷°��ӵ� �ִ� �ӵ� ����
	Vector2 gravity = mGravity;
	gravity.Normalize();
	float dot = math::Dot(mVelocity, gravity);
	gravity = gravity * dot;

	// sideVelocity = �� �ӵ� - �߷�
	// ���Ʒ��� �ִ� �ӵ��� �߷¿� ������ �޴´�.
	Vector2 sideVelocity = mVelocity - gravity;
	if (mLimitedVelocity.y < gravity.Length())
	{
		gravity.Normalize();
		gravity *= mLimitedVelocity.y;
	}


	// �¿�δ� ���� ������ �ȴ�
	if (mLimitedVelocity.x < sideVelocity.Length())
	{
		sideVelocity.Normalize();
		sideVelocity *= mLimitedVelocity.x;
	}

	// ������ ���� ( ����� ���� ����, �ӵ��� 0�� �ƴ�)
	if (!(mVelocity == Vector2::Zero))
	{
		//�ӵ��� �ݴ�������� �������� ����ȴ�.
		Vector2 friction = -mVelocity;
		friction = friction.Normalize() * mFriction * mMass * Time::DeltaTime();

		//���������� ���� �ӵ� ���Ҵ� ���� �ӵ����� ū ���
		// �������� �� ū��� �ӵ��� 0
		if (mVelocity.Length() < friction.Length())
		{
			mVelocity = Vector2::Zero;
		}
		// �������� �ӵ����� ���� ���
		// �������� �����ָ� �ȴ�.
		else
		{
			mVelocity += friction;
		}
	}

	// �ӵ��� �°Բ� ��ü�� �̵���Ų��.
	Transform* tr = GetOwner()->GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	pos = pos + mVelocity * Time::DeltaTime();

	tr->SetPos(pos);
	// ��� Force�� ���������� ��� �̵��ϴϱ� 
	// Force�� �ٽ� �ʱ�ȭ ������Ѵ�.
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
