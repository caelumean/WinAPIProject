#include "NomadWagonScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "Transform.h"
#include "Object.h"

//BG
#include "NomadWagonBG.h"
#include "NomadWagonNPCBG.h"
#include "NomadWagonNPC.h"

//UI
#include "TownCommonUI1.h"
#include "TownCommonUI2.h"

NomadWagonScene::NomadWagonScene()
{
}

NomadWagonScene::~NomadWagonScene()
{
}

void NomadWagonScene::Initialize()
{
	Scene::Initialize();
	//BG
	object::Instantiate<NomadWagonBG>(eLayerType::BackGround);
	object::Instantiate<NomadWagonNPCBG>(eLayerType::Shadow);
	object::Instantiate<NomadWagonNPC>(eLayerType::NPC);

	//UI
	object::Instantiate<TownCommonUI1>(eLayerType::UI1);
	object::Instantiate<TownCommonUI2>(eLayerType::UI2);
}

void NomadWagonScene::Update()
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
