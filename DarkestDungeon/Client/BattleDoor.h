#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class BattleDoor : public GameObject
{
public:
	BattleDoor();
	~BattleDoor();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
	Animator* mAnimator;
	Transform* tr;

};