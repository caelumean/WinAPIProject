#pragma once
#include "Scene.h"

class NomadWagonBG;
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
	NomadWagonBG* mNomadWagonBG;
};

