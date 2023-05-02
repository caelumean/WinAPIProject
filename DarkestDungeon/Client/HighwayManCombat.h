#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class HighwayManCombat : public GameObject
{
public:
	enum class eCrusaderState
	{
		Combat,
		Death
	};
	HighwayManCombat();
	~HighwayManCombat();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	void death();

private:
	eCrusaderState mState;
	Animator* mAnimator;

};
