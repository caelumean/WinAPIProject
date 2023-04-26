#include "BlacksmithScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "Transform.h"
#include "Object.h"
//BG
#include "BlacksmithBG.h"
#include "BlacksmithNPC.h"
#include "BlacksmithNPCBG.h"

//UI
#include "TownCommonUI1.h"
#include "BlacksmithFrame.h"

BlacksmithScene::BlacksmithScene()
{
}

BlacksmithScene::~BlacksmithScene()
{
}

void BlacksmithScene::Initialize()
{
	Scene::Initialize();
	//BG
	object::Instantiate<BlacksmithBG>(eLayerType::BackGround);
	object::Instantiate<BlacksmithNPCBG>(eLayerType::Shadow);
	object::Instantiate<BlacksmithNPC>(eLayerType::NPC);

	//UI
	object::Instantiate<BlacksmithFrame>(eLayerType::UI1);

	//UI
	object::Instantiate<TownCommonUI1>(eLayerType::UI1);
}

void BlacksmithScene::Update()
{
	if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}

	Scene::Update();
}

void BlacksmithScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void BlacksmithScene::Release()
{
	Scene::Release();
}

void BlacksmithScene::OnEnter()
{
}

void BlacksmithScene::OnExit()
{
}
