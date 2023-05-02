#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class BoneArbalest : public GameObject
{
public:
	enum class eBoneArbalestState
	{
		Idle,
		Death
	};
	BoneArbalest();
	~BoneArbalest();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	void idle();
	void death();

private:
	eBoneArbalestState mState;
	Animator* mAnimator;
};

