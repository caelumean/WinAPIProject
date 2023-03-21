#pragma once
#include "Scene.h"

//BG
class RuinsBG;
//player
class Crusader;
class HighwayMan;
class PlagueDoctor;
class Vestal;
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
	HighwayMan* mHighwayMan;
	PlagueDoctor* mPlagueDoctor;
	Vestal* mVestal;
};