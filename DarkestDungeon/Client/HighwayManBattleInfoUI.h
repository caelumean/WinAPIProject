#pragma once
#include "GameObject.h"
#include "Image.h"

class HighwayManBattleInfoUI : public GameObject
{
public:
	HighwayManBattleInfoUI();
	~HighwayManBattleInfoUI();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage[7];
	float mTime;
};