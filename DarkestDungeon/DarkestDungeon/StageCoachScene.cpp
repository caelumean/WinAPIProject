#include "StageCoachScene.h"
#include "StageCoachBG.h"
#include "SceneManager.h"
#include "Input.h"

StageCoachScene::StageCoachScene()
{
}

StageCoachScene::~StageCoachScene()
{
}

void StageCoachScene::Initialize()
{
	mStageCoachBG = new StageCoachBG();
	AddGameObeject(mStageCoachBG, eLayerType::BackGround);

	Scene::Initialize();
}

void StageCoachScene::Update()
{
	if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}

	Scene::Update();
}

void StageCoachScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void StageCoachScene::Release()
{
	Scene::Release();
}

void StageCoachScene::OnEnter()
{
}

void StageCoachScene::OnExit()
{
}
