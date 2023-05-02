#include "MemoirsScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "Transform.h"
#include "Object.h"
//BG
#include "MemoirsBG.h"
#include "MemoirsNPCBG.h"
#include "MemoirsNPC.h"

//UI
#include "TownCommonUI1.h"
#include "TownCommonUI2.h"

MemoirsScene::MemoirsScene()
{
}

MemoirsScene::~MemoirsScene()
{
}

void MemoirsScene::Initialize()
{
	Scene::Initialize();
	//BG
	object::Instantiate<MemoirsBG>(eLayerType::BackGround);
	object::Instantiate<MemoirsNPCBG>(eLayerType::Shadow);
	object::Instantiate<MemoirsNPC>(eLayerType::NPC);

	//UI
	object::Instantiate<TownCommonUI1>(eLayerType::UI1);
	object::Instantiate<TownCommonUI2>(eLayerType::UI2);
}
void MemoirsScene::Update()
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

void MemoirsScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void MemoirsScene::Release()
{
	Scene::Release();
}

void MemoirsScene::OnEnter()
{
}

void MemoirsScene::OnExit()
{
}
