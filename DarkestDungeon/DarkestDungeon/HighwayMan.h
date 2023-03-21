#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class Animation;
class HighwayMan : public GameObject
{
public:
	enum class eHighwayManState
	{
		Walk,
		Combat,
		Idle,
	};
	HighwayMan();
	~HighwayMan();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	void walk();
	void combat();
	void idle();

private:
	eHighwayManState mState;
	Animator* mAnimator;
};