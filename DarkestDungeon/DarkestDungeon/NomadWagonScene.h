#pragma once
#include "Scene.h"

class NomadWagonBG;
class NomadWagonNPCBG;
class NomadWagonNPC;
class ProgressionBar;
class Namesplate;
class NomadWagonScene : public Scene
{
public:
	NomadWagonScene();
	~NomadWagonScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;

private:
	//BG
	NomadWagonBG* mNomadWagonBG;
	NomadWagonNPCBG* mNomadWagonNPCBG;
	NomadWagonNPC* mNomadWagonNPC;

	//UI
	ProgressionBar* mProgressionBar;
	Namesplate* mNamesplate;
};

