#include "ProvisionScene.h"
#include "ProvisionBG.h"
#include "Input.h"
#include "SceneManager.h"

ProvisionScene::ProvisionScene()
{
}

ProvisionScene::~ProvisionScene()
{
}

void ProvisionScene::Initialize()
{
	//¹è°æ
	mProvisionBG = new ProvisionBG();
	AddGameObeject(mProvisionBG, eLayerType::BackGround);

	Scene::Initialize();
}

void ProvisionScene::Update()
{
	if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Play);
	}

	Scene::Update();
}

void ProvisionScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void ProvisionScene::Release()
{
	Scene::Release();
}

void ProvisionScene::OnEnter()
{
}

void ProvisionScene::OnExit()
{
}
