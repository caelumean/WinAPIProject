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

	// ���� �������ִ� �Լ�
	void SetMass(float mass) { mMass = mass; }
	// ���� �������� �� �ִ� �Լ�
	void AddForce(Vector2 force);

	void SetGround(bool ground) { mbGround = ground; }
	void SetVelocity(Vector2 velocity) { mVelocity = velocity; }
	Vector2 GetVelocity() { return mVelocity; }

private :
	// ����
	float mMass;
	// ��
	Vector2 mForce;
	// ���ӵ� : ���ӵ��� ũ�⸦ �̺��̶� �Ѵ�.
	Vector2 mAccelation;
	// �ӵ� : ����� ũ�⸦ ���ÿ� ���� ��
	Vector2 mVelocity;

	// �ִ�ӵ�
	Vector2 mLimitedVelocity;

	// �߷�
	Vector2 mGravity;
	// ������
	float mFriction;
	//���� �پ����� �ƴ���
	bool mbGround;


	// ���ݴ� ������ ������ �����ϰڴ� �ϸ� �������� �ʿ��ϴ�
	/*float mStaticFriction;
	float mKineticFriction;*/
	//float mCoefficientFriction;
	//float mNormalForce;

};

