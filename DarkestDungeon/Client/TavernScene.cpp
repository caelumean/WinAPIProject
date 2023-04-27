#include "TavernScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "Transform.h"
#include "Object.h"

//BG
#include "TavernBG.h"
#include "TavernNPCBG.h"
#include "TavernNPC.h"

//UI
#include "TownCommonUI1.h"
#include "TownCommonUI2.h"
#include "BlacksmithFrame.h"

TavernScene::TavernScene()
{
}

TavernScene::~TavernScene()
{
}

void TavernScene::Initialize()
{
	Scene::Initialize();
	//BG
	object::Instantiate<TavernBG>(eLayerType::BackGround);
	object::Instantiate<TavernNPCBG>(eLayerType::Shadow);
	object::Instantiate<TavernNPC>(eLayerType::NPC);

	//UI
	object::Instantiate<TownCommonUI1>(eLayerType::UI1);
	object::Instantiate<TownCommonUI2>(eLayerType::UI2);
}

void TavernScene::Update()
{
	Scene::Update();
	Vector2 MousePos = Input::GetMousePos();
	if ((MousePos.x > 1270 && MousePos.x < 1300) && (MousePos.y > 120 && MousePos.y < 150))
	{
		if (Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			SceneManager::LoadScene(eSceneType::Town);
		}
	}

}

void TavernScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void TavernScene::Release()
{
	Scene::Release();
}

void TavernScene::OnEnter()
{
}

void TavernScene::OnExit()
{
}
