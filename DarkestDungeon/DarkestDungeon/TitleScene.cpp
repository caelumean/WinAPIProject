#include "TitleBG.h"
#include "TitleHouse.h"
#include "Logo.h"
#include "StartButton.h"
#include "TitleScene.h"
#include "Input.h"
#include "SceneManager.h"


TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Initialize()
{
	//¹è°æ
	mTitleBG = new TitleBG();
	AddGameObeject(mTitleBG, eLayerType::BackGround);
	// house
	mTitleHouse = new TitleHouse();
	AddGameObeject(mTitleHouse, eLayerType::Shadow);
	// Logo
	mLogo = new Logo();
	AddGameObeject(mLogo, eLayerType::UI1);
	// start Button
	mStartButton = new StartButton();
	AddGameObeject(mStartButton, eLayerType::UI1);
	

	Scene::Initialize();
}

void TitleScene::Update()
{
	if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}
	else if (Input::GetKeyState(eKeyCode::A) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Play);
	}
	Scene::Update();
}

void TitleScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void TitleScene::Release()
{
	Scene::Release();
}

void TitleScene::OnEnter()
{
}

void TitleScene::OnExit()
{
}
