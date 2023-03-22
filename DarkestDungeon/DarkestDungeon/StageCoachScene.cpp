#include "StageCoachScene.h"
#include "SceneManager.h"
#include "Input.h"

//BG
#include "StageCoachBG.h"
#include "StageCoachNPCBG.h"
#include "StageCoachNPC.h"

//UI
#include "ProgressionBar.h"
#include "Namesplate.h"

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
	mProgressionBar = new ProgressionBar();
	AddGameObeject(mProgressionBar, eLayerType::UI1);
	mNamesplate = new Namesplate();
	AddGameObeject(mNamesplate, eLayerType::Sky);

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
