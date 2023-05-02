#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class BoneCourtier : public GameObject
{
public:
	enum class eBoneCourtierState
	{
		Idle,
		Death
	};
	BoneCourtier();
	~BoneCourtier();
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	void idle();
	void death();

private:
	eBoneCourtierState mState;
	Animator* mAnimator;
};

