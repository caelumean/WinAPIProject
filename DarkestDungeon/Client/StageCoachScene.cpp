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
#include "TownCommonUI2.h"

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
	object::Instantiate<TownCommonUI2>(eLayerType::UI2);
}

void StageCoachScene::Update()
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
