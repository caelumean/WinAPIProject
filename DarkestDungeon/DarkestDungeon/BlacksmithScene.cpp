#include "BlacksmithScene.h"
#include "SceneManager.h"
#include "Input.h"

//BG
#include "BlacksmithBG.h"
#include "BlacksmithNPC.h"
#include "BlacksmithNPCBG.h"

//UI
#include "ProgressionBar.h"
#include "Namesplate.h"
#include "BlacksmithFrame.h"

BlacksmithScene::BlacksmithScene()
{
}

BlacksmithScene::~BlacksmithScene()
{
}

void BlacksmithScene::Initialize()
{
	//BG
	mBlacksmithBG = new BlacksmithBG();
	AddGameObeject(mBlacksmithBG, eLayerType::BackGround);
	mBlacksmithNPCBG = new BlacksmithNPCBG();
	AddGameObeject(mBlacksmithNPCBG, eLayerType::Shadow);
	mBlacksmithNPC = new BlacksmithNPC();
	AddGameObeject(mBlacksmithNPC, eLayerType::NPC);

	//UI
	mProgressionBar = new ProgressionBar();
	AddGameObeject(mProgressionBar, eLayerType::UI1);
	mNamesplate = new Namesplate();
	AddGameObeject(mNamesplate, eLayerType::Sky);
	mBlacksmithFrame = new BlacksmithFrame();
	AddGameObeject(mBlacksmithFrame, eLayerType::UI1);


	Scene::Initialize();
}

void BlacksmithScene::Update()
{
	if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}

	Scene::Update();
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
