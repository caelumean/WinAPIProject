#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class CrusaderCombat : public GameObject
{
public:
	enum class eCrusaderState
	{
		Combat,
		Death
	};
	CrusaderCombat();
	~CrusaderCombat();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	void SetHP(int hp) { Hp = hp; }
	int GetHP() { return Hp; }
	int GetDodge() { return Dodge; }
	int GetSpeed() { return Speed; }
	int GetMinDamage() { return MinDamage; }
	int GetMaxDamage() { return MaxDamage; }

private:

	void death();

private:
	eCrusaderState mState;
	Animator* mAnimator;

	int Hp;
	int Dodge;
	int Speed;
	int MinDamage;
	int MaxDamage;

};