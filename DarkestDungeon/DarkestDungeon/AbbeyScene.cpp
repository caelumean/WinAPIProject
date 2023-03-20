#include "AbbeyScene.h"
#include "SceneManager.h"
#include "Input.h"
//BG
#include "AbbeyBG.h"
#include "AbbeyNPCBG.h"
#include "AbbeyNPC.h"
//UI
#include "ProgressionBar.h"
#include "Namesplate.h"


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
	mProgressionBar = new ProgressionBar();
	AddGameObeject(mProgressionBar, eLayerType::UI1);
	mNamesplate = new Namesplate();
	AddGameObeject(mNamesplate, eLayerType::Sky);

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
