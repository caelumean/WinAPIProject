#include "GraveyardScene.h"
#include "SceneManager.h"
#include "Input.h"

// BG
#include "GraveyardBG.h"
#include "GraveyardNPCBG.h"
#include "GraveyardNPC.h"

//UI
#include "ProgressionBar.h"
#include "Namesplate.h"

GraveyardScene::GraveyardScene()
{
}

GraveyardScene::~GraveyardScene()
{
}

void GraveyardScene::Initialize()
{
	//BG
	mGraveyardBG = new GraveyardBG();
	AddGameObeject(mGraveyardBG, eLayerType::BackGround);
	mGraveyardNPCBG = new GraveyardNPCBG();
	AddGameObeject(mGraveyardNPCBG, eLayerType::Shadow);
	mGraveyardNPC = new GraveyardNPC();
	AddGameObeject(mGraveyardNPC, eLayerType::NPC);

	//UI
	mProgressionBar = new ProgressionBar();
	AddGameObeject(mProgressionBar, eLayerType::UI1);
	mNamesplate = new Namesplate();
	AddGameObeject(mNamesplate, eLayerType::Sky);
	Scene::Initialize();
}

void GraveyardScene::Update()
{
	if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}

	Scene::Update();
}

void GraveyardScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void GraveyardScene::Release()
{
	Scene::Release();
}

void GraveyardScene::OnEnter()
{
}

void GraveyardScene::OnExit()
{
}
