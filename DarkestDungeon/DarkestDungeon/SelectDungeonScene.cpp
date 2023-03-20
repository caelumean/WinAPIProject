#include "SelectDungeonScene.h"
#include "SelectDungeonBG.h"
#include "Input.h"
#include "SceneManager.h"

SelectDungeonScene::SelectDungeonScene()
{
}

SelectDungeonScene::~SelectDungeonScene()
{
}

void SelectDungeonScene::Initialize()
{
	mSelectDungeonBG = new SelectDungeonBG();
	AddGameObeject(mSelectDungeonBG, eLayerType::BackGround);

	Scene::Initialize();
}

void SelectDungeonScene::Update()
{
	if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}
	//N АјБо
	else if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Provision);
	}

	Scene::Update();
}

void SelectDungeonScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void SelectDungeonScene::Release()
{
	Scene::Release();
}

void SelectDungeonScene::OnEnter()
{
}

void SelectDungeonScene::OnExit()
{
}
