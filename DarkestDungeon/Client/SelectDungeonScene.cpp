#include "SelectDungeonScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "Transform.h"
#include "Object.h"
#include "Sound.h"
#include "Resources.h"
// BG
#include "SelectDungeonBG.h"

//UI
#include "TownCommonUI1.h"
#include "TripButton.h"
#include "SelectDungeonUI.h"

SelectDungeonScene::SelectDungeonScene()
{
}

SelectDungeonScene::~SelectDungeonScene()
{
}

void SelectDungeonScene::Initialize()
{
	Scene::Initialize();
	Towntheme = Resources::Load<Sound>(L"TownTheme", L"..\\Resources\\Sound\\BGM\\Town.wav");
	Towntheme->Play(true);
	//BG
	object::Instantiate<SelectDungeonBG>(eLayerType::BackGround);

	//UI
	object::Instantiate<TownCommonUI1>(eLayerType::UI1);
	object::Instantiate<TripButton>(eLayerType::UI2);
	object::Instantiate<SelectDungeonUI>(eLayerType::UI2);
}

void SelectDungeonScene::Update()
{
	Scene::Update();
	Vector2 MousePos = Input::GetMousePos();

	// Trip Button
	if ((MousePos.x > 680 && MousePos.x < 980) && (MousePos.y > 803 && MousePos.y < 850))
	{
		if (Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			SceneManager::LoadScene(eSceneType::Provision);
		}
	}
	if (Input::GetKeyState(eKeyCode::ESC) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}
	
}

void SelectDungeonScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void SelectDungeonScene::Release()
{
	Scene::Release();
}

void SelectDungeonScene::OnEnter()
{
	Towntheme->Play(true);
	Scene::OnEnter();
}

void SelectDungeonScene::OnExit()
{
	Towntheme->Stop(true);
	Scene::OnExit();
}
