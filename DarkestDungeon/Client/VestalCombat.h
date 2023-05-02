#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class VestalCombat : public GameObject
{
public:
	enum class eVestalState
	{
		Combat,
		Death
	};
	VestalCombat();
	~VestalCombat();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:

	void death();

private:
	eVestalState mState;
	Animator* mAnimator;

};

