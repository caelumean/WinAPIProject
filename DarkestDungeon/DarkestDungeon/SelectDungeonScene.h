#pragma once
#include "Scene.h"

class SelectDungeonBG;
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
};
