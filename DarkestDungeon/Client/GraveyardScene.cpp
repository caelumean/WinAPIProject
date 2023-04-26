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
}

void GraveyardScene::Update()
{
	if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}

	Scene::Update();
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
