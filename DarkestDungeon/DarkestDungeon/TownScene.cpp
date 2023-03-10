#include "TownScene.h"
#include "TownBG.h"
#include "SceneManager.h"
#include "Input.h"

TownScene::TownScene()
{
}

TownScene::~TownScene()
{
}

void TownScene::Initialize()
{
	mTownBG = new TownBG();
	AddGameObeject(mTownBG, eLayerType::BackGround);

	Scene::Initialize();
}

void TownScene::Update()
{
	if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Title);
	}
	// N을 누르면 selectDungeon 으로 가기
	/*if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Title);
	}*/

	Scene::Update();
}

void TownScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void TownScene::Release()
{
	Scene::Release();
}

void TownScene::OnEnter()
{
}

void TownScene::OnExit()
{
}
