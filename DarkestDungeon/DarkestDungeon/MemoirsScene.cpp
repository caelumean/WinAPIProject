#include "MemoirsScene.h"
#include "SceneManager.h"
#include "Input.h"

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
	//BG
	mMemoirsBG = new MemoirsBG();
	AddGameObeject(mMemoirsBG, eLayerType::BackGround);
	mMemoirsNPCBG = new MemoirsNPCBG();
	AddGameObeject(mMemoirsNPCBG, eLayerType::Shadow);
	mMemoirsNPC = new MemoirsNPC();
	AddGameObeject(mMemoirsNPC, eLayerType::NPC);

	//UI
	mTownCommonUI1 = new TownCommonUI1();
	AddGameObeject(mTownCommonUI1, eLayerType::UI1);

	Scene::Initialize();
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
