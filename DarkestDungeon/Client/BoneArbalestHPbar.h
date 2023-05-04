#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class BoneArbalestHPbar : public GameObject
{
public:
	BoneArbalestHPbar();
	~BoneArbalestHPbar();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
	Animator* mAnimator;
	class Transform* tr;

};