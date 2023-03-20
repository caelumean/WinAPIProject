#include "GuildScene.h"
#include "GuildBG.h"
#include "SceneManager.h"
#include "Input.h"

GuildScene::GuildScene()
{
}

GuildScene::~GuildScene()
{
}

void GuildScene::Initialize()
{
	mGuildBG = new GuildBG();
	AddGameObeject(mGuildBG, eLayerType::BackGround);

	Scene::Initialize();
}

void GuildScene::Update()
{
	if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}

	Scene::Update();
}

void GuildScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void GuildScene::Release()
{
	Scene::Release();
}

void GuildScene::OnEnter()
{
}

void GuildScene::OnExit()
{
}
