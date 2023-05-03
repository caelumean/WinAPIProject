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
	class CrusaderCombat* mCrusader;
	class HighwayManCombat* mHighwayMan;
	class PlagueDoctorCombat* mPlagueDoctor;
	class VestalCombat* mVestal;

	// Map Inventory
	class DGMapBG* mDGMapBG;
	class DGInventoryBG* mDGInventoryBG;

	// Hero Info UI
	class CrusaderBattleInfoUI* mCrusaderInfoUI;
	class HighwayManInfoUI* mHighwayManInfoUI;
	class PlagueDoctorInfoUI* mPlagueDoctorInfoUI;
	class VestalInfoUI* mVestalInfoUI;

	// Select UI
	class BattleSelectbarUI* mCrusaderSelectUI;
	//class SelectbarUI* mHighwayManSelectUI;
	//class SelectbarUI* mPlagueDoctorSelectUI;
	//class SelectbarUI* mVestalSelectUI;

	class CrusaderDefend* mCrusaderDefend;
	class CrusaderSword* mCrusaderSword;

	//Monster
	class BoneDefender* mBoneDefender;
	class BoneSoldier* mBoneSoldier;
	class BoneCourtier* mBoneCourtier;
	class BoneArbalest* mBoneArbalest;

	int HeroMember;
	int MonsterMember;
	float mTime;
	float mEndTime;
	bool End;
	bool Crusaderturn = false;

	// »ç¿îµå
	class Sound* CombatTheme;

};