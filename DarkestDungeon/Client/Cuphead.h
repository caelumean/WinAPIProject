#pragma once
#include "GameObject.h"

class Rigidbody;
// Cuphead�� �ִϸ��̼��� ����� ���̱� ������ AnimatorClass �߰�
class Animator;
class Cuphead : public GameObject
{
public:
	enum class eCupheadState
	{
		Move,
		Shoot,
		Death,
		Idle,
	};
	Cuphead();
	~Cuphead();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc);
	virtual void Release() override;

	virtual void OnCollisionEnter(class Collider* other) override;
	virtual void OnCollisionStay(class Collider* other) override;
	virtual void OnCollisionExit(class Collider* other) override;


private:
	void move();
	void shoot();
	void death();
	void idle();

private:
	eCupheadState mState;
	Animator* mAnimator;
	Rigidbody* mRigidbody;
};
