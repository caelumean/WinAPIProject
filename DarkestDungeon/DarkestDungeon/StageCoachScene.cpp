#include "StageCoachScene.h"
#include "SceneManager.h"
#include "Input.h"

//BG
#include "StageCoachBG.h"
#include "StageCoachNPCBG.h"
#include "StageCoachNPC.h"
//UI
#include "TownCommonUI1.h"

StageCoachScene::StageCoachScene()
{
}

StageCoachScene::~StageCoachScene()
{
}

void StageCoachScene::Initialize()
{
	//BG
	mStageCoachBG = new StageCoachBG();
	AddGameObeject(mStageCoachBG, eLayerType::BackGround);
	mStageCoachNPC = new StageCoachNPC();
	mStageCoachNPCBG = new StageCoachNPCBG();
	AddGameObeject(mStageCoachNPCBG, eLayerType::Shadow);
	AddGameObeject(mStageCoachNPC, eLayerType::NPC);

	//UI
	mTownCommonUI1 = new TownCommonUI1();
	AddGameObeject(mTownCommonUI1, eLayerType::UI1);
	Scene::Initialize();
}

void StageCoachScene::Update()
{
	if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}

	Scene::Update();
}

void StageCoachScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void StageCoachScene::Release()
{
	Scene::Release();
}

void StageCoachScene::OnEnter()
{
}

void StageCoachScene::OnExit()
{
}
