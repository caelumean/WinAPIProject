#include "TavernScene.h"
#include "TavernBG.h"
#include "SceneManager.h"
#include "Input.h"

TavernScene::TavernScene()
{
}

TavernScene::~TavernScene()
{
}

void TavernScene::Initialize()
{
	mTavernBG = new TavernBG();
	AddGameObeject(mTavernBG, eLayerType::BackGround);

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
