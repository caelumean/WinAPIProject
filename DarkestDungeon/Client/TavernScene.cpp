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
}

void TavernScene::Update()
{
	if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}

	Scene::Update();
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
