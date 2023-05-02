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
#include "TownCommonUI2.h"


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
	object::Instantiate<TownCommonUI2>(eLayerType::UI2);
}

void GuildScene::Update()
{
	Scene::Update();
	Vector2 MousePos = Input::GetMousePos();
	if ((MousePos.x > 1270 && MousePos.x < 1300) && (MousePos.y > 120 && MousePos.y < 150))
	{
		if (Input::GetKeyState(eKeyCode::LBUTTON) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::Town);
		}
	}
	if (Input::GetKeyState(eKeyCode::ESC) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}

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
