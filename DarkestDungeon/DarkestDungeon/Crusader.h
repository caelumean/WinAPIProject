#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class Crusader : public GameObject
{
public:
	enum class eCrusaderState
	{
		Walk,
		Combat,
		Idle,
	};
	Crusader();
	~Crusader();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	void walk ();
	void combat();
	void idle();

private:
	eCrusaderState mState;
	Animator* mAnimator;
};