#include "GraveyardScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "Transform.h"
#include "Object.h"

// BG
#include "GraveyardBG.h"
#include "GraveyardNPCBG.h"
#include "GraveyardNPC.h"

//UI
#include "TownCommonUI1.h"
#include "TownCommonUI2.h"


GraveyardScene::GraveyardScene()
{
}

GraveyardScene::~GraveyardScene()
{
}

void GraveyardScene::Initialize()
{
	Scene::Initialize();
	//BG
	object::Instantiate<GraveyardBG>(eLayerType::BackGround);
	object::Instantiate<GraveyardNPCBG>(eLayerType::Shadow);
	object::Instantiate<GraveyardNPC>(eLayerType::NPC);

	//UI
	object::Instantiate<TownCommonUI1>(eLayerType::UI1);
	object::Instantiate<TownCommonUI2>(eLayerType::UI2);
}

void GraveyardScene::Update()
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
