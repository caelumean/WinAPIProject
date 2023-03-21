#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class Animation;
class Vestal : public GameObject
{
public:
	enum class eVestalState
	{
		Walk,
		Combat,
		Idle,
	};
	Vestal();
	~Vestal();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	void walk();
	void combat();
	void idle();

private:
	eVestalState mState;
	Animator* mAnimator;
};