#include "GuildScene.h"
#include "SceneManager.h"
#include "Input.h"

//BG
#include "GuildBG.h"
#include "GuildNPCBG.h"
#include "GuildNPC.h"
//UI
#include "TownCommonUI1.h"

GuildScene::GuildScene()
{
}

GuildScene::~GuildScene()
{
}

void GuildScene::Initialize()
{
	//BG
	mGuildBG = new GuildBG();
	AddGameObeject(mGuildBG, eLayerType::BackGround);
	mGuildNPCBG = new GuildNPCBG();
	AddGameObeject(mGuildNPCBG, eLayerType::Shadow);
	mGuildNPC = new GuildNPC();
	AddGameObeject(mGuildNPC, eLayerType::NPC);

	//UI
	mTownCommonUI1 = new TownCommonUI1();
	AddGameObeject(mTownCommonUI1, eLayerType::UI1);

	Scene::Initialize();
}

void GuildScene::Update()
{
	if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}

	Scene::Update();
}

void GuildScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void GuildScene::Release()
{
	Scene::Release();
}

void GuildScene::OnEnter()
{
}

void GuildScene::OnExit()
{
}
