#pragma once
#include "Scene.h"

class SanitariumBG;
class SanitariumNPC;
class SanitariumNPCBG;
//UI
class TownCommonUI1;
class SanitariumScene : public Scene
{
public:
	SanitariumScene();
	~SanitariumScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;
private:
	//BG
	SanitariumBG* mSanitariumBG;
	SanitariumNPCBG* mSanitariumNPCBG;
	SanitariumNPC* mSanitariumNPC;
	//UI
	TownCommonUI1* mTownCommonUI1;
};

