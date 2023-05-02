#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class Crusader : public GameObject
{
public:
	enum class eCrusaderState
	{
		Move,
		Idle,
		Death
	};
	Crusader();
	~Crusader();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;
	
private:
	void move();
	void idle();
	void death();

private:
	eCrusaderState mState;
	Animator* mAnimator;

};

