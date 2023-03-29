#include "SurvivalistScene.h"
#include "SceneManager.h"
#include "Input.h"
//BG
#include "SurvivalistBG.h"
#include "SurvivalistNPCBG.h"
#include "SurvivalistNPC.h"
//UI
#include "TownCommonUI1.h"

SurvivalistScene::SurvivalistScene()
{
}

SurvivalistScene::~SurvivalistScene()
{
}

void SurvivalistScene::Initialize()
{
	//BG
	mSurvivalistBG = new SurvivalistBG();
	AddGameObeject(mSurvivalistBG, eLayerType::BackGround);
	mSurvivalistNPCBG = new SurvivalistNPCBG();
	AddGameObeject(mSurvivalistNPCBG, eLayerType::Shadow);
	mSurvivalistNPC = new SurvivalistNPC();
	AddGameObeject(mSurvivalistNPC, eLayerType::NPC);

	//UI
	mTownCommonUI1 = new TownCommonUI1();
	AddGameObeject(mTownCommonUI1, eLayerType::UI1);
	Scene::Initialize();
}

void SurvivalistScene::Update()
{
	if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}

	Scene::Update();
}

void SurvivalistScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void SurvivalistScene::Release()
{
	Scene::Release();
}

void SurvivalistScene::OnEnter()
{
}

void SurvivalistScene::OnExit()
{
}
