#include "SurvivalistScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "Transform.h"
#include "Object.h"

//BG
#include "SurvivalistBG.h"
#include "SurvivalistNPCBG.h"
#include "SurvivalistNPC.h"
//UI
#include "TownCommonUI1.h"
#include "TownCommonUI2.h"

SurvivalistScene::SurvivalistScene()
{
}

SurvivalistScene::~SurvivalistScene()
{
}

void SurvivalistScene::Initialize()
{
	Scene::Initialize();
	//BG
	object::Instantiate<SurvivalistBG>(eLayerType::BackGround);
	object::Instantiate<SurvivalistNPCBG>(eLayerType::Shadow);
	object::Instantiate<SurvivalistNPC>(eLayerType::NPC);

	//UI
	object::Instantiate<TownCommonUI1>(eLayerType::UI1);
	object::Instantiate<TownCommonUI2>(eLayerType::UI2);
}

void SurvivalistScene::Update()
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

void SurvivalistScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void SurvivalistScene::Release()
{
	Scene::Release();
}

void SurvivalistScene::OnEnter()
{
}

void SurvivalistScene::OnExit()
{
}
