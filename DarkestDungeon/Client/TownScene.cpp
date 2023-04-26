#include "TownScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "Transform.h"
#include "Object.h"

//BG
#include "TownBG.h"
#include "TownGround.h"
#include "TownRuins.h"

// 건물
#include "BuildingsObject.h"

//UI
#include "TownCommonUI1.h"


TownScene::TownScene()
{
}

TownScene::~TownScene()
{
}

void TownScene::Initialize()
{
	Scene::Initialize();
	//BG
	object::Instantiate<TownBG>(eLayerType::BackGround);
	object::Instantiate<TownRuins>(eLayerType::Shadow);
	object::Instantiate<TownGround>(eLayerType::Shadow);

	//건물
	object::Instantiate<BuildingsObject>(eLayerType::Building);

	//UI
	object::Instantiate<TownCommonUI1>(eLayerType::UI1);
}

void TownScene::Update()
{
	Scene::Update();
	Vector2 MousePos = Input::GetMousePos();

	if ((MousePos.x > 620 && MousePos.x < 1020) && (MousePos.y > 200 && MousePos.y < 400))
	{
		if (Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			SceneManager::LoadScene(eSceneType::Abbey);
		}
	}
	if ((MousePos.x > 1150 && MousePos.x < 1430) && (MousePos.y > 450 && MousePos.y < 750))
	{
		if (Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			SceneManager::LoadScene(eSceneType::Blacksmith);
		}
	}
	if ((MousePos.x > 610 && MousePos.x < 860) && (MousePos.y > 480 && MousePos.y < 580))
	{
		if (Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			SceneManager::LoadScene(eSceneType::Graveyard);
		}	
	}
	if ((MousePos.x > 960 && MousePos.x < 1260) && (MousePos.y > 300 && MousePos.y < 700))
	{
		if (Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			SceneManager::LoadScene(eSceneType::Guild);
		}
	}
	if ((MousePos.x > 660 && MousePos.x < 810) && (MousePos.y > 530 && MousePos.y < 730))
	{
		if (Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			SceneManager::LoadScene(eSceneType::Memoirs);
		}
	}
	if ((MousePos.x > 780 && MousePos.x < 980) && (MousePos.y > 600 && MousePos.y < 750))
	{
		if (Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			SceneManager::LoadScene(eSceneType::NomadWagon);
		}
	}
	if ((MousePos.x > 430 && MousePos.x < 730) && (MousePos.y > 150 && MousePos.y < 550))
	{
		if (Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			SceneManager::LoadScene(eSceneType::Sanitarium);
		}
	}
	if ((MousePos.x > 140 && MousePos.x < 340) && (MousePos.y > 580 && MousePos.y < 710))
	{
		if (Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			SceneManager::LoadScene(eSceneType::StageCoach);
		}
	}
	if ((MousePos.x > 80 && MousePos.x < 240) && (MousePos.y > 380 && MousePos.y < 520))
	{
		if (Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			SceneManager::LoadScene(eSceneType::Survivalist);
		}
	}
	if ((MousePos.x > 300 && MousePos.x < 560) && (MousePos.y > 410 && MousePos.y < 680))
	{
		if (Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			SceneManager::LoadScene(eSceneType::Tavern);
		}
	}
}

void TownScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void TownScene::Release()
{
	Scene::Release();
}

void TownScene::OnEnter()
{
}

void TownScene::OnExit()
{
}
