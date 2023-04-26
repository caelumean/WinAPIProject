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
}

void SurvivalistScene::Update()
{
	if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}

	Scene::Update();
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
