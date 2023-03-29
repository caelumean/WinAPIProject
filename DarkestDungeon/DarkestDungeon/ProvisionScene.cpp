#include "ProvisionScene.h"
#include "Input.h"
#include "SceneManager.h"

//BG
#include "ProvisionBG.h"
//UI
#include "TownCommonUI1.h"

ProvisionScene::ProvisionScene()
{
}

ProvisionScene::~ProvisionScene()
{
}

void ProvisionScene::Initialize()
{
	//BG
	mProvisionBG = new ProvisionBG();
	AddGameObeject(mProvisionBG, eLayerType::BackGround);

	// UI
	mTownCommonUI1 = new TownCommonUI1();
	AddGameObeject(mTownCommonUI1, eLayerType::UI1);


	Scene::Initialize();
}

void ProvisionScene::Update()
{
	if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Play);
	}
	else if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::SelectDugeon);
	}

	Scene::Update();
}

void ProvisionScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void ProvisionScene::Release()
{
	Scene::Release();
}

void ProvisionScene::OnEnter()
{
}

void ProvisionScene::OnExit()
{
}
