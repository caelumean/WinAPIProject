#include "PlayRuinsScene.h"
#include "Crusader.h"
#include "RuinsBG.h"
#include "Input.h"
#include "SceneManager.h"
#include "CollisionManager.h"

PlayRuinsScene::PlayRuinsScene()
{
	
}

PlayRuinsScene::~PlayRuinsScene()
{
}

void PlayRuinsScene::Initialize()
{
	//배경
	mRuinsBG = new RuinsBG();
	AddGameObeject(mRuinsBG, eLayerType::BackGround);
	
	//캐릭터
	mCrusader = new Crusader();
	AddGameObeject(mCrusader, eLayerType::Player);

	Scene::Initialize();
}

void PlayRuinsScene::Update()
{
	if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}

	Scene::Update();
}

void PlayRuinsScene::Render(HDC hdc)
{
	
	Scene::Render(hdc);
}

void PlayRuinsScene::Release()
{
	Scene::Release();
}

void PlayRuinsScene::OnEnter()
{
}

void PlayRuinsScene::OnExit()
{
}
