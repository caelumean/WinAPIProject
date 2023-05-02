#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class HighwayMan : public GameObject
{
public:
	enum class eHighwayManState
	{
		Move,
		Idle,
		Death
	};
	HighwayMan();
	~HighwayMan();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	void move();
	void idle();
	void death();

private:
	eHighwayManState mState;
	Animator* mAnimator;
};

