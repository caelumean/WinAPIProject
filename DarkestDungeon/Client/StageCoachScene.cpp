#include "StageCoachScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "Transform.h"
#include "Object.h"

//BG
#include "StageCoachBG.h"
#include "StageCoachNPCBG.h"
#include "StageCoachNPC.h"
//UI
#include "TownCommonUI1.h"

StageCoachScene::StageCoachScene()
{
}

StageCoachScene::~StageCoachScene()
{
}

void StageCoachScene::Initialize()
{
	Scene::Initialize();
	//BG
	object::Instantiate<StageCoachBG>(eLayerType::BackGround);
	object::Instantiate<StageCoachNPC>(eLayerType::Shadow);
	object::Instantiate<StageCoachNPCBG>(eLayerType::NPC);

	//UI
	object::Instantiate<TownCommonUI1>(eLayerType::UI1);
}

void StageCoachScene::Update()
{
	if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}

	Scene::Update();
}

void StageCoachScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void StageCoachScene::Release()
{
	Scene::Release();
}

void StageCoachScene::OnEnter()
{
}

void StageCoachScene::OnExit()
{
}
