#pragma once
#include "Scene.h"

//BG
class TownBG;
class TownGround;
class TownRuins;
//Building
class AbbeyBuilding;
class BlacksmithBuilding;
class GraveyardBuilding;
class GuildBuilding;
class MemoirsBuilding;
class NomadWagonBuilding;
class SanitariumBuilding;
class StageCoachBuilding;
class SurvivalistBuilding;
class TavernBuilding;
//UI
class ProgressionBar;
class Namesplate;

class TownScene : public Scene
{
public:
	TownScene();
	~TownScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;
private:
	//BG
	TownBG* mTownBG;
	TownGround* mTownGround;
	TownRuins* mTownRuins;

	// °Ç¹°
	AbbeyBuilding* mAbbeyBuilding;
	BlacksmithBuilding* mBlacksmithBuilding;
	GraveyardBuilding* mGraveyardBuilding;
	GuildBuilding* mGuildBuilding;
	MemoirsBuilding* mMemoirsBuilding;
	NomadWagonBuilding* mNomadWagonBuilding;
	SanitariumBuilding* mSanitariumBuilding;
	StageCoachBuilding* mStageCoachBuilding;
	SurvivalistBuilding* mSurvivalistBuilding;
	TavernBuilding* mTavernBuilding;

	//UI
	ProgressionBar* mProgressionBar;
	Namesplate* mNamesplate;

};

