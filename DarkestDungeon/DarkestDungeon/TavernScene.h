#pragma once
#include "Scene.h"

class TavernBG;
class TavernScene : public Scene
{
public:
	TavernScene();
	~TavernScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;
private:
	TavernBG* mTavernBG;
};

