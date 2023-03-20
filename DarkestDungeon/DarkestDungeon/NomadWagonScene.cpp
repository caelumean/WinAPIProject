#include "NomadWagonScene.h"
#include "NomadWagonBG.h"
#include "SceneManager.h"
#include "Input.h"

NomadWagonScene::NomadWagonScene()
{
}

NomadWagonScene::~NomadWagonScene()
{
}

void NomadWagonScene::Initialize()
{
	mNomadWagonBG = new NomadWagonBG();
	AddGameObeject(mNomadWagonBG, eLayerType::BackGround);

	Scene::Initialize();
}

void NomadWagonScene::Update()
{
	if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}

	Scene::Update();
}

void NomadWagonScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void NomadWagonScene::Release()
{
	Scene::Release();
}

void NomadWagonScene::OnEnter()
{
}

void NomadWagonScene::OnExit()
{
}
