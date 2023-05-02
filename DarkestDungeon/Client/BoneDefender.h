#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class BoneDefender : public GameObject
{
public:
	enum class eBoneDefenderState
	{
		Idle,
		Attack,
		Defend,
		Death
	};
	BoneDefender();
	~BoneDefender();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	void idle();
	void attack();
	void defend();
	void death();

private:
	eBoneDefenderState mState;
	Animator* mAnimator;
};