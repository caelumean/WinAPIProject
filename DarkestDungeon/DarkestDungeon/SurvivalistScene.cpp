#include "SurvivalistScene.h"
#include "SurvivalistBG.h"
#include "SceneManager.h"
#include "Input.h"

SurvivalistScene::SurvivalistScene()
{
}

SurvivalistScene::~SurvivalistScene()
{
}

void SurvivalistScene::Initialize()
{
	mSurvivalistBG = new SurvivalistBG();
	AddGameObeject(mSurvivalistBG, eLayerType::BackGround);

	Scene::Initialize();
}

void SurvivalistScene::Update()
{
	if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}

	Scene::Update();
}

void SurvivalistScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void SurvivalistScene::Release()
{
	Scene::Release();
}

void SurvivalistScene::OnEnter()
{
}

void SurvivalistScene::OnExit()
{
}
