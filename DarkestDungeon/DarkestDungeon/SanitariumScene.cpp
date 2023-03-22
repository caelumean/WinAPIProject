#include "SanitariumScene.h"
#include "SceneManager.h"
#include "Input.h"

//BG
#include "SanitariumBG.h"
#include "SanitariumNPCBG.h"
#include "SanitariumNPC.h"
//UI
#include "ProgressionBar.h"
#include "Namesplate.h"

SanitariumScene::SanitariumScene()
{
}

SanitariumScene::~SanitariumScene()
{
}

void SanitariumScene::Initialize()
{
	//BG
	mSanitariumBG = new SanitariumBG();
	AddGameObeject(mSanitariumBG, eLayerType::BackGround);
	mSanitariumNPCBG = new SanitariumNPCBG();
	AddGameObeject(mSanitariumNPCBG, eLayerType::Shadow);
	mSanitariumNPC = new SanitariumNPC();
	AddGameObeject(mSanitariumNPC, eLayerType::NPC);

	//UI
	mProgressionBar = new ProgressionBar();
	AddGameObeject(mProgressionBar, eLayerType::UI1);
	mNamesplate = new Namesplate();
	AddGameObeject(mNamesplate, eLayerType::Sky);

	Scene::Initialize();
}

void SanitariumScene::Update()
{
	if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}

	Scene::Update();
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
