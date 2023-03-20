#pragma once
#include "Scene.h"

class GraveyardBG;
class GraveyardNPCBG;
class GraveyardNPC;
class ProgressionBar;
class Namesplate;
class GraveyardScene : public Scene
{
public:
	GraveyardScene();
	~GraveyardScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;
private:
	//BG
	GraveyardBG* mGraveyardBG;
	GraveyardNPCBG* mGraveyardNPCBG;
	GraveyardNPC* mGraveyardNPC;

	//UI
	ProgressionBar* mProgressionBar;
	Namesplate* mNamesplate;
};

