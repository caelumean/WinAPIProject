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
#include "TownCommonUI2.h"
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
	object::Instantiate<TownCommonUI2>(eLayerType::UI2);
}

void BlacksmithScene::Update()
{
	Scene::Update();
	Vector2 MousePos = Input::GetMousePos();
	if ((MousePos.x > 1270 && MousePos.x < 1300) && (MousePos.y > 120 && MousePos.y < 150))
	{
		if (Input::GetKeyState(eKeyCode::LBUTTON) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::Town);
		}
	}
	if (Input::GetKeyState(eKeyCode::ESC) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}

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
