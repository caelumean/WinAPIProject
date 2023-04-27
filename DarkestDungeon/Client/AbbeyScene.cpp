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
#include "TownCommonUI2.h"

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
	//UI
	object::Instantiate<TownCommonUI2>(eLayerType::UI2);
}

void AbbeyScene::Update()
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
