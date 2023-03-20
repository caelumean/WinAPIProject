#include "GraveyardScene.h"
#include "GraveyardBG.h"
#include "SceneManager.h"
#include "Input.h"

GraveyardScene::GraveyardScene()
{
}

GraveyardScene::~GraveyardScene()
{
}

void GraveyardScene::Initialize()
{
	mGraveyardBG = new GraveyardBG();
	AddGameObeject(mGraveyardBG, eLayerType::BackGround);

	Scene::Initialize();
}

void GraveyardScene::Update()
{
	if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}

	Scene::Update();
}

void GraveyardScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void GraveyardScene::Release()
{
	Scene::Release();
}

void GraveyardScene::OnEnter()
{
}

void GraveyardScene::OnExit()
{
}
