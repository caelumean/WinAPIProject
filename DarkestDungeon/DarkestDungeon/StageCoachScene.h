#pragma once
#include "Scene.h"

class StageCoachBG;
class StageCoachNPC;
class StageCoachNPCBG;
//UI
class TownCommonUI1;
class StageCoachScene : public Scene
{
public:
	StageCoachScene();
	~StageCoachScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;
private:
	//BG
	StageCoachBG* mStageCoachBG;
	StageCoachNPCBG* mStageCoachNPCBG;
	StageCoachNPC* mStageCoachNPC;

	//UI
	TownCommonUI1* mTownCommonUI1;;
};

