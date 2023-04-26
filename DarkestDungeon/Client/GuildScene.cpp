#include "GuildScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "Transform.h"
#include "Object.h"

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
	Scene::Initialize();
	//BG
	object::Instantiate<GuildBG>(eLayerType::BackGround);
	object::Instantiate<GuildNPCBG>(eLayerType::Shadow);
	object::Instantiate<GuildNPC>(eLayerType::NPC);

	//UI
	object::Instantiate<TownCommonUI1>(eLayerType::UI1);
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
