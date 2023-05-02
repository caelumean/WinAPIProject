#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class PlagueDoctorStressbar : public GameObject
{
public:
	PlagueDoctorStressbar();
	~PlagueDoctorStressbar();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
	Animator* mAnimator;
	Transform* tr;

};