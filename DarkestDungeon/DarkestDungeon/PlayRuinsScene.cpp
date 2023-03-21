#include "PlayRuinsScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "CollisionManager.h"
//BG
#include "RuinsBG.h"
// player
#include "Crusader.h"
#include "HighwayMan.h"
#include "PlagueDoctor.h"
#include "Vestal.h"

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
	mHighwayMan = new HighwayMan();
	AddGameObeject(mHighwayMan, eLayerType::Player);
	mPlagueDoctor = new PlagueDoctor();
	AddGameObeject(mPlagueDoctor, eLayerType::Player);
	mVestal = new Vestal();
	AddGameObeject(mVestal, eLayerType::Player);

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
