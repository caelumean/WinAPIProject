#include "SanitariumScene.h"
#include "SanitariumBG.h"
#include "SceneManager.h"
#include "Input.h"

SanitariumScene::SanitariumScene()
{
}

SanitariumScene::~SanitariumScene()
{
}

void SanitariumScene::Initialize()
{
	mSanitariumBG = new SanitariumBG();
	AddGameObeject(mSanitariumBG, eLayerType::BackGround);

	Scene::Initialize();
}

void SanitariumScene::Update()
{
	if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}

	Scene::Update();
}

void SanitariumScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void SanitariumScene::Release()
{
	Scene::Release();
}

void SanitariumScene::OnEnter()
{
}

void SanitariumScene::OnExit()
{
}
