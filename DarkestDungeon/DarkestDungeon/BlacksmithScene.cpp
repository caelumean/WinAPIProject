#include "BlacksmithScene.h"
#include "BlacksmithBG.h"
#include "SceneManager.h"
#include "Input.h"

BlacksmithScene::BlacksmithScene()
{
}

BlacksmithScene::~BlacksmithScene()
{
}

void BlacksmithScene::Initialize()
{
	mBlacksmithBG = new BlacksmithBG();
	AddGameObeject(mBlacksmithBG, eLayerType::BackGround);

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
