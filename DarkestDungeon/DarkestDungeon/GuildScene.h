#pragma once
#include "Scene.h"

class GuildBG;
class GuildNPCBG;
class GuildNPC;
//UI
class ProgressionBar;
class Namesplate;
class GuildScene : public Scene
{
public:
	GuildScene();
	~GuildScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;
private:

	//BG
	GuildBG* mGuildBG;
	GuildNPCBG* mGuildNPCBG;
	GuildNPC* mGuildNPC;

	//UI
	ProgressionBar* mProgressionBar;
	Namesplate* mNamesplate;

};

