#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class PlagueDoctorCombat : public GameObject
{
public:
	enum class ePlagueDoctorState
	{
		Combat,
		Death
	};
	PlagueDoctorCombat();
	~PlagueDoctorCombat();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;


private:
	void death();

private:
	ePlagueDoctorState mState;
	Animator* mAnimator;
};

