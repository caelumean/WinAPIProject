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
}
void MemoirsScene::Update()
{
	if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}

	Scene::Update();
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
