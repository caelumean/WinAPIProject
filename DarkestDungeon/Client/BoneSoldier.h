#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class BoneSoldier : public GameObject
{
public:
	enum class eBoneSoldierState
	{
		Idle,
		Death
	};
	BoneSoldier();
	~BoneSoldier();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	void idle();
	void death();

private:
	eBoneSoldierState mState;
	Animator* mAnimator;
};