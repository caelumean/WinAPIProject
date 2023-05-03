#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class StackofBooks : public GameObject
{
public:
	StackofBooks();
	~StackofBooks();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
	Animator* mAnimator;
	class Transform* tr;

};