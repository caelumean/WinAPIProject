#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class VestalHPbar : public GameObject
{
public:
	VestalHPbar();
	~VestalHPbar();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
	Animator* mAnimator;
	Transform* tr;

};

