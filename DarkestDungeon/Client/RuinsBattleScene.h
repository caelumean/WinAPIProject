#pragma once
#include "Scene.h"

class RuinsBattleScene : public Scene
{
public:
	RuinsBattleScene();
	~RuinsBattleScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;

private:
	// Player
	class Crusader* mCrusader;
	class HighwayMan* mHighwayMan;
	class PlagueDoctor* mPlagueDoctor;
	class Vestal* mVestal;

	// Map Inventory
	class DGMapBG* mDGMapBG;
	class DGInventoryBG* mDGInventoryBG;

	// Hero Info UI
	class CrusaderInfoUI* mCrusaderInfoUI;
	class HighwayManInfoUI* mHighwayManInfoUI;
	class PlagueDoctorInfoUI* mPlagueDoctorInfoUI;
	class VestalInfoUI* mVestalInfoUI;

};