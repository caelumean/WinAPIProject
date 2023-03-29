#include "NomadWagonScene.h"
#include "SceneManager.h"
#include "Input.h"

//BG
#include "NomadWagonBG.h"
#include "NomadWagonNPCBG.h"
#include "NomadWagonNPC.h"

//UI
#include "TownCommonUI1.h"

NomadWagonScene::NomadWagonScene()
{
}

NomadWagonScene::~NomadWagonScene()
{
}

void NomadWagonScene::Initialize()
{
	//BG
	mNomadWagonBG = new NomadWagonBG();
	AddGameObeject(mNomadWagonBG, eLayerType::BackGround);
	mNomadWagonNPCBG = new NomadWagonNPCBG();
	AddGameObeject(mNomadWagonNPCBG, eLayerType::Shadow);
	mNomadWagonNPC = new NomadWagonNPC();
	AddGameObeject(mNomadWagonNPC, eLayerType::NPC);

	//UI
	mTownCommonUI1 = new TownCommonUI1();
	AddGameObeject(mTownCommonUI1, eLayerType::UI1);;

	Scene::Initialize();
}

void NomadWagonScene::Update()
{
	if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}

	Scene::Update();
}

void NomadWagonScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void NomadWagonScene::Release()
{
	Scene::Release();
}

void NomadWagonScene::OnEnter()
{
}

void NomadWagonScene::OnExit()
{
}
