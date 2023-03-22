#include "TavernScene.h"
#include "SceneManager.h"
#include "Input.h"

//BG
#include "TavernBG.h"
#include "TavernNPCBG.h"
#include "TavernNPC.h"
//UI
#include "ProgressionBar.h"
#include "Namesplate.h"

TavernScene::TavernScene()
{
}

TavernScene::~TavernScene()
{
}

void TavernScene::Initialize()
{
	//BG
	mTavernBG = new TavernBG();
	AddGameObeject(mTavernBG, eLayerType::BackGround);
	mTavernNPCBG = new TavernNPCBG();
	AddGameObeject(mTavernNPCBG, eLayerType::Shadow);
	mTavernNPC = new TavernNPC();
	AddGameObeject(mTavernNPC, eLayerType::NPC);

	//UI
	mProgressionBar = new ProgressionBar();
	AddGameObeject(mProgressionBar, eLayerType::UI1);
	mNamesplate = new Namesplate();
	AddGameObeject(mNamesplate, eLayerType::Sky);

	Scene::Initialize();
}

void TavernScene::Update()
{
	if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}

	Scene::Update();
}

void TavernScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void TavernScene::Release()
{
	Scene::Release();
}

void TavernScene::OnEnter()
{
}

void TavernScene::OnExit()
{
}
