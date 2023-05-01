#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class PlagueDoctor : public GameObject
{
public:
	enum class ePlagueDoctorState
	{
		Move,
		Idle,
		Combat,
		Death
	};
	PlagueDoctor();
	~PlagueDoctor();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;


private:
	void move();
	void idle();
	void combat();
	void death();

private:
	ePlagueDoctorState mState;
	Animator* mAnimator;
};
