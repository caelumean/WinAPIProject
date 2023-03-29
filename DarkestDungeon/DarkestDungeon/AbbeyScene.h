#pragma once
#include "Scene.h"

class AbbeyBG;
class AbbeyNPCBG;
class AbbeyNPC;
class TownCommonUI1;

class AbbeyScene : public Scene
{
public:
	AbbeyScene();
	~AbbeyScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;
private:
	//BG
	AbbeyBG* mAbbeyBG;
	AbbeyNPCBG* mAbbeyNPCBG;
	AbbeyNPC* mAbbeyNPC;
	//UI
	TownCommonUI1* mTownCommonUI1;
};

