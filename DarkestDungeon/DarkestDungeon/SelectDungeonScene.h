#pragma once
#include "Scene.h"

class SelectDungeonBG;
//UI1
class TownCommonUI1;

class SelectDungeonScene : public Scene
{
public:
	SelectDungeonScene();
	~SelectDungeonScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;

private:
	SelectDungeonBG* mSelectDungeonBG;

	//UI1
	TownCommonUI1* mTownCommonUI1;
};
