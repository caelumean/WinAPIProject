#pragma once
#include "Scene.h"

//BG
class TownBG;
class TownGround;
class TownRuins;

//Building
class BuildingsObject;
//UI1
class TownCommonUI1;

class TownScene : public Scene
{
public:
	TownScene();
	~TownScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;
private:
	//BG
	TownBG* mTownBG;
	TownGround* mTownGround;
	TownRuins* mTownRuins;

	// °Ç¹°
	BuildingsObject* mBuildingsObject;

	//UI1
	TownCommonUI1* mTownCommonUI1;

};

