#include "MemoirsScene.h"
#include "MemoirsBG.h"
#include "SceneManager.h"
#include "Input.h"

MemoirsScene::MemoirsScene()
{
}

MemoirsScene::~MemoirsScene()
{
}

void MemoirsScene::Initialize()
{
	mMemoirsBG = new MemoirsBG();
	AddGameObeject(mMemoirsBG, eLayerType::BackGround);

	Scene::Initialize();
}

void MemoirsScene::Update()
{
	if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}

	Scene::Update();
}

void MemoirsScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void MemoirsScene::Release()
{
	Scene::Release();
}

void MemoirsScene::OnEnter()
{
}

void MemoirsScene::OnExit()
{
}
