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
#include "TownCommonUI2.h"

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
	object::Instantiate<TownCommonUI2>(eLayerType::UI2);
}

void SanitariumScene::Update()
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
