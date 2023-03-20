#include "TownScene.h"
#include "TownBG.h"
#include "TownGround.h"
#include "AbbeyBuilding.h"
#include "BlacksmithBuilding.h"
#include "GraveyardBuilding.h"
#include "GuildBuilding.h"
#include "MemoirsBuilding.h"
#include "NomadWagonBuilding.h"
#include "SanitariumBuilding.h"
#include "StageCoachBuilding.h"
#include "SurvivalistBuilding.h"
#include "TavernBuilding.h"
#include "SceneManager.h"
#include "Input.h"

TownScene::TownScene()
{
}

TownScene::~TownScene()
{
}

void TownScene::Initialize()
{
	mTownBG = new TownBG();
	AddGameObeject(mTownBG, eLayerType::BackGround);

	mTownGround = new TownGround();
	AddGameObeject(mTownGround, eLayerType::Shadow);

	

	// 건물
	mAbbeyBuilding = new AbbeyBuilding();
	AddGameObeject(mAbbeyBuilding, eLayerType::Building);
	mGuildBuilding = new GuildBuilding();
	AddGameObeject(mGuildBuilding, eLayerType::Building);
	mBlacksmithBuilding = new BlacksmithBuilding();
	AddGameObeject(mBlacksmithBuilding, eLayerType::Building);
	mGraveyardBuilding = new GraveyardBuilding();
	AddGameObeject(mGraveyardBuilding, eLayerType::Building);
	
	mSanitariumBuilding = new SanitariumBuilding();
	AddGameObeject(mSanitariumBuilding, eLayerType::Building);
	mTavernBuilding = new TavernBuilding();
	AddGameObeject(mTavernBuilding, eLayerType::Building);
	mStageCoachBuilding = new StageCoachBuilding();
	AddGameObeject(mStageCoachBuilding, eLayerType::Building);
	mSurvivalistBuilding = new SurvivalistBuilding();
	AddGameObeject(mSurvivalistBuilding, eLayerType::Building);

	mMemoirsBuilding = new MemoirsBuilding();
	AddGameObeject(mMemoirsBuilding, eLayerType::Building);
	mNomadWagonBuilding = new NomadWagonBuilding();
	AddGameObeject(mNomadWagonBuilding, eLayerType::Building);
	
	
	

	Scene::Initialize();
}

void TownScene::Update()
{
	if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Title);
	}
	// Q abbey
	else if (Input::GetKeyState(eKeyCode::Q) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Abbey);
	}
	// W blacksmith
	else if (Input::GetKeyState(eKeyCode::W) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Blacksmith);
	}
	// E Graveyard
	else if (Input::GetKeyState(eKeyCode::E) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Graveyard);
	}
	// R Guild
	else if (Input::GetKeyState(eKeyCode::R) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Guild);
	}
	// T Memoirs
	else if (Input::GetKeyState(eKeyCode::T) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Memoirs);
	}
	// Y Nomad
	else if (Input::GetKeyState(eKeyCode::Y) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::NomadWagon);
	}
	// U Sanitarium
	else if (Input::GetKeyState(eKeyCode::U) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Sanitarium);
	}
	// I StageCoach
	else if (Input::GetKeyState(eKeyCode::I) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::StageCoach);
	}
	// O Survivalist
	else if (Input::GetKeyState(eKeyCode::O) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Survivalist);
	}
	// P Tavern
	else if (Input::GetKeyState(eKeyCode::P) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Tavern);
	}

	// N을 누르면 selectDungeon 으로 가기
	else if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::SelectDugeon);
	}

	Scene::Update();
}

void TownScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void TownScene::Release()
{
	Scene::Release();
}

void TownScene::OnEnter()
{
}

void TownScene::OnExit()
{
}
