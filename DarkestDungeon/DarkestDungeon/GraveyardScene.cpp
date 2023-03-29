#include "GraveyardScene.h"
#include "SceneManager.h"
#include "Input.h"

// BG
#include "GraveyardBG.h"
#include "GraveyardNPCBG.h"
#include "GraveyardNPC.h"

//UI
#include "TownCommonUI1.h"

GraveyardScene::GraveyardScene()
{
}

GraveyardScene::~GraveyardScene()
{
}

void GraveyardScene::Initialize()
{
	//BG
	mGraveyardBG = new GraveyardBG();
	AddGameObeject(mGraveyardBG, eLayerType::BackGround);
	mGraveyardNPCBG = new GraveyardNPCBG();
	AddGameObeject(mGraveyardNPCBG, eLayerType::Shadow);
	mGraveyardNPC = new GraveyardNPC();
	AddGameObeject(mGraveyardNPC, eLayerType::NPC);

	//UI
	mTownCommonUI1 = new TownCommonUI1();
	AddGameObeject(mTownCommonUI1, eLayerType::UI1);
	Scene::Initialize();
}

void GraveyardScene::Update()
{
	if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}

	Scene::Update();
}

void GraveyardScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void GraveyardScene::Release()
{
	Scene::Release();
}

void GraveyardScene::OnEnter()
{
}

void GraveyardScene::OnExit()
{
}
