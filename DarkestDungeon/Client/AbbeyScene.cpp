#include "AbbeyScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "Transform.h"
#include "Object.h"

//BG
#include "AbbeyBG.h"
#include "AbbeyNPCBG.h"
#include "AbbeyNPC.h"

//UI
#include "TownCommonUI1.h"

AbbeyScene::AbbeyScene()
{
}

AbbeyScene::~AbbeyScene()
{
}

void AbbeyScene::Initialize()
{
	Scene::Initialize();
	//BG
	object::Instantiate<AbbeyBG>(eLayerType::BackGround);
	object::Instantiate<AbbeyNPCBG>(eLayerType::Shadow);
	object::Instantiate<AbbeyNPC>(eLayerType::NPC);

	//UI
	object::Instantiate<TownCommonUI1>(eLayerType::UI1);
}

void AbbeyScene::Update()
{
	if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}
	Scene::Update();
}

void AbbeyScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void AbbeyScene::Release()
{
	Scene::Release();
}

void AbbeyScene::OnEnter()
{
}

void AbbeyScene::OnExit()
{
}
