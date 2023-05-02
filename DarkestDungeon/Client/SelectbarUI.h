#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class SelectbarUI : public GameObject
{
public:
	SelectbarUI();
	~SelectbarUI();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
	Animator* mAnimator;
	Transform* tr;

};

