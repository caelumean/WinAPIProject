#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class DiscardedPack : public GameObject
{
public:
	DiscardedPack();
	~DiscardedPack();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
	Animator* mAnimator;
	class Transform* tr;

};