#pragma once
#include "Scene.h"

class SurvivalistBG;
class SurvivalistNPCBG;
class SurvivalistNPC;
class ProgressionBar;
class Namesplate;
class SurvivalistScene : public Scene
{
public:
	SurvivalistScene();
	~SurvivalistScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;

private:
	//BG
	SurvivalistBG* mSurvivalistBG;
	SurvivalistNPCBG* mSurvivalistNPCBG;
	SurvivalistNPC* mSurvivalistNPC;
	//UI
	ProgressionBar* mProgressionBar;
	Namesplate* mNamesplate;
};