#pragma once
#include "Scene.h"

class TownBG;
class TownGround;
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
class ProgresstionBar;
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
	TownBG* mTownBG;
	TownGround* mTownGround;

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
	ProgresstionBar* mProgresstionBar;

};

