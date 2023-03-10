#pragma once
#include "Scene.h"

class StageCoachBG;
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
	StageCoachBG* mStageCoachBG;
};

