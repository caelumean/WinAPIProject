#pragma once
#include "Scene.h"

//class Crusader;

class RuinsEntranceScene : public Scene
{
public:
	RuinsEntranceScene();
	~RuinsEntranceScene();

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

};