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
