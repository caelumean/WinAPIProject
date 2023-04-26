#include "SanitariumScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "Transform.h"
#include "Object.h"

//BG
#include "SanitariumBG.h"
#include "SanitariumNPCBG.h"
#include "SanitariumNPC.h"
//UI
#include "TownCommonUI1.h"

SanitariumScene::SanitariumScene()
{
}

SanitariumScene::~SanitariumScene()
{
}

void SanitariumScene::Initialize()
{
	Scene::Initialize();
	//BG
	object::Instantiate<SanitariumBG>(eLayerType::BackGround);
	object::Instantiate<SanitariumNPCBG>(eLayerType::Shadow);
	object::Instantiate<SanitariumNPC>(eLayerType::NPC);

	//UI
	object::Instantiate<TownCommonUI1>(eLayerType::UI1);
}

void SanitariumScene::Update()
{
	if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}

	Scene::Update();
}

void SanitariumScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void SanitariumScene::Release()
{
	Scene::Release();
}

void SanitariumScene::OnEnter()
{
}

void SanitariumScene::OnExit()
{
}
