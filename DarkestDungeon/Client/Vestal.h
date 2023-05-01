#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class Vestal : public GameObject
{
public:
	enum class eVestalState
	{
		Move,
		Idle,
		Combat,
		Death
	};
	Vestal();
	~Vestal();

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
	eVestalState mState;
	Animator* mAnimator;
};
