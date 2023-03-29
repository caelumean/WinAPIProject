#pragma once
#include "Scene.h"

class BlacksmithBG;
class BlacksmithNPC;
class BlacksmithNPCBG;
class BlacksmithFrame;

//UI1
class TownCommonUI1;

class BlacksmithScene : public Scene
{
public:
	BlacksmithScene();
	~BlacksmithScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;

private:
	//BG
	BlacksmithBG* mBlacksmithBG;
	BlacksmithNPC* mBlacksmithNPC;
	BlacksmithNPCBG* mBlacksmithNPCBG;
	//UI
	TownCommonUI1* mTownCommonUI1;
	BlacksmithFrame* mBlacksmithFrame;

};

