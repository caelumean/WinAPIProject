#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class BattleSelectbarUI : public GameObject
{
public:
	BattleSelectbarUI();
	~BattleSelectbarUI();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
	Animator* mAnimator;
	class Transform* tr;
	float mTime;
};
