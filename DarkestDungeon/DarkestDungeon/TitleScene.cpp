#include "TitleBG.h"
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

	Scene::Initialize();
}

void TitleScene::Update()
{
	if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
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
