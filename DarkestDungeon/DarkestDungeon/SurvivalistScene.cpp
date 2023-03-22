#include "SurvivalistScene.h"
#include "SceneManager.h"
#include "Input.h"
//BG
#include "SurvivalistBG.h"
#include "SurvivalistNPCBG.h"
#include "SurvivalistNPC.h"

//UI
#include "ProgressionBar.h"
#include "Namesplate.h"

SurvivalistScene::SurvivalistScene()
{
}

SurvivalistScene::~SurvivalistScene()
{
}

void SurvivalistScene::Initialize()
{
	//BG
	mSurvivalistBG = new SurvivalistBG();
	AddGameObeject(mSurvivalistBG, eLayerType::BackGround);
	mSurvivalistNPCBG = new SurvivalistNPCBG();
	AddGameObeject(mSurvivalistNPCBG, eLayerType::Shadow);
	mSurvivalistNPC = new SurvivalistNPC();
	AddGameObeject(mSurvivalistNPC, eLayerType::NPC);

	//UI
	mProgressionBar = new ProgressionBar();
	AddGameObeject(mProgressionBar, eLayerType::UI1);
	mNamesplate = new Namesplate();
	AddGameObeject(mNamesplate, eLayerType::Sky);

	Scene::Initialize();
}

void SurvivalistScene::Update()
{
	if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}

	Scene::Update();
}

void SurvivalistScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void SurvivalistScene::Release()
{
	Scene::Release();
}

void SurvivalistScene::OnEnter()
{
}

void SurvivalistScene::OnExit()
{
}
