#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class HighwayManHPbar : public GameObject
{
public:
	HighwayManHPbar();
	~HighwayManHPbar();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
	Animator* mAnimator;
	Transform* tr;

};
{
};

