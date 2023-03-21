#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class Animation;
class PlagueDoctor : public GameObject
{
public:
	enum class ePlagueDoctorState
	{
		Walk,
		Combat,
		Idle,
	};
	PlagueDoctor();
	~PlagueDoctor();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	void walk();
	void combat();
	void idle();

private:
	ePlagueDoctorState mState;
	Animator* mAnimator;
};