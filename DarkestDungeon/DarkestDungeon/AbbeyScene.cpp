#include "AbbeyScene.h"
#include "AbbeyBG.h"
#include "SceneManager.h"
#include "Input.h"

AbbeyScene::AbbeyScene()
{
}

AbbeyScene::~AbbeyScene()
{
}

void AbbeyScene::Initialize()
{
	mAbbeyBG = new AbbeyBG();
	AddGameObeject(mAbbeyBG, eLayerType::BackGround);

	Scene::Initialize();
}

void AbbeyScene::Update()
{
	if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}
	
	Scene::Update();
}

void AbbeyScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void AbbeyScene::Release()
{
	Scene::Release();
}

void AbbeyScene::OnEnter()
{
	
}

void AbbeyScene::OnExit()
{
}
