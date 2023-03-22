#pragma once
#include "Scene.h"

class SanitariumBG;
class SanitariumNPC;
class SanitariumNPCBG;
class ProgressionBar;
class Namesplate;
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
	ProgressionBar* mProgressionBar;
	Namesplate* mNamesplate;
};

