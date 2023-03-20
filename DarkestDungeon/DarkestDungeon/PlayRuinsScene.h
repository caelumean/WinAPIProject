#pragma once
#include "Scene.h"

class Crusader;
class RuinsBG;
class PlayRuinsScene : public Scene
{
public:
	PlayRuinsScene();
	~PlayRuinsScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;

private:
	RuinsBG* mRuinsBG;
	Crusader* mCrusader;
};