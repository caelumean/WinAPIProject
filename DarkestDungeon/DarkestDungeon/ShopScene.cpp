#include "ShopScene.h"
#include "RuinsBG.h"
#include "Input.h"
#include "SceneManager.h"

ShopScene::ShopScene()
{
}

ShopScene::~ShopScene()
{
}

void ShopScene::Initialize()
{
	//¹è°æ
	mRuinsBG = new RuinsBG();
	AddGameObeject(mRuinsBG, eLayerType::BackGround);

	Scene::Initialize();
}

void ShopScene::Update()
{
	if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::SelectDugeon);
	}

	Scene::Update();
}

void ShopScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void ShopScene::Release()
{
	Scene::Release();
}

void ShopScene::OnEnter()
{
}

void ShopScene::OnExit()
{
}
