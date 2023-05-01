#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class Crusader : public GameObject
{
public:
	enum class eCrusaderState
	{
		Move,
		Idle,
		Combat,
		Death
	};
	Crusader();
	~Crusader();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnCollisionEnter(class Collider* other) override;
	virtual void OnCollisionStay(class Collider* other) override;
	virtual void OnCollisionExit(class Collider* other) override;
private:
	void move();
	void idle();
	void combat();
	void death();

private:
	eCrusaderState mState;
	Animator* mAnimator;
};

