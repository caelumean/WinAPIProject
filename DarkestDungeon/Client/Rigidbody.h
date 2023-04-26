#pragma once
#include "Component.h"

class Rigidbody : public Component
{
public:
	Rigidbody();
	~Rigidbody();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	// 질량 세팅해주는 함수
	void SetMass(float mass) { mMass = mass; }
	// 힘을 증가해줄 수 있는 함수
	void AddForce(Vector2 force);

	void SetGround(bool ground) { mbGround = ground; }
	void SetVelocity(Vector2 velocity) { mVelocity = velocity; }
	Vector2 GetVelocity() { return mVelocity; }

private :
	// 질량
	float mMass;
	// 힘
	Vector2 mForce;
	// 가속도 : 가속도의 크기를 미분이라 한다.
	Vector2 mAccelation;
	// 속도 : 방향과 크기를 동시에 가진 것
	Vector2 mVelocity;

	// 최대속도
	Vector2 mLimitedVelocity;

	// 중력
	Vector2 mGravity;
	// 마찰력
	float mFriction;
	//땅에 붙었는지 아닌지
	bool mbGround;


	// 조금더 물리에 가깝게 구현하겠다 하면 이정도는 필요하다
	/*float mStaticFriction;
	float mKineticFriction;*/
	//float mCoefficientFriction;
	//float mNormalForce;

};

