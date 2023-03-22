#include "MemoirsScene.h"
#include "SceneManager.h"
#include "Input.h"

//BG
#include "MemoirsBG.h"
#include "MemoirsNPCBG.h"
#include "MemoirsNPC.h"

//UI
#include "ProgressionBar.h"
#include "Namesplate.h"

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
	mProgressionBar = new ProgressionBar();
	AddGameObeject(mProgressionBar, eLayerType::UI1);
	mNamesplate = new Namesplate();
	AddGameObeject(mNamesplate, eLayerType::Sky);

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
