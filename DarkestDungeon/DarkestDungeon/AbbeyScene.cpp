#include "AbbeyScene.h"
#include "SceneManager.h"
#include "Input.h"
//BG
#include "AbbeyBG.h"
#include "AbbeyNPCBG.h"
#include "AbbeyNPC.h"
//UI
#include "TownCommonUI1.h"


AbbeyScene::AbbeyScene()
{
}

AbbeyScene::~AbbeyScene()
{
}

void AbbeyScene::Initialize()
{
	//BG
	mAbbeyBG = new AbbeyBG();
	AddGameObeject(mAbbeyBG, eLayerType::BackGround);
	// npc BG
	mAbbeyNPCBG = new AbbeyNPCBG();
	AddGameObeject(mAbbeyNPCBG, eLayerType::Shadow);
	mAbbeyNPC = new AbbeyNPC();
	AddGameObeject(mAbbeyNPC, eLayerType::NPC);

	//UI
	mTownCommonUI1 = new TownCommonUI1();
	AddGameObeject(mTownCommonUI1, eLayerType::UI1);

	Scene::Initialize();
}

void AbbeyScene::Update()
{
	if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}
	
	Scene::Update();
}

void AbbeyScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void AbbeyScene::Release()
{
	Scene::Release();
}

void AbbeyScene::OnEnter()
{
	
}

void AbbeyScene::OnExit()
{
}
