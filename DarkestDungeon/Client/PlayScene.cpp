#include "PlayScene.h"
#include "Cuphead.h"
#include "Input.h"
#include "SceneManager.h"
#include "Monster.h"
#include "CollisionManager.h"
#include "Transform.h"
#include "Camera.h"
#include "Object.h"

PlayScene::PlayScene()
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::Initialize()
{
	/*mCuphead = new Cuphead();
	AddGameObject(mCuphead, eLayerType::Player);*/
	Scene::Initialize();

	Cuphead* player = object::Instantiate<Cuphead>(Vector2(500.0f, 400.0f), eLayerType::Player);
	//object::Instantiate<Monster>(Vector2(500.0f, 500.0f), eLayerType::Monster);
	//object::Instantiate<Monster>(Vector2(500.0f, 500.0f), eLayerType::Monster);
	
	// 카메라 세팅 부분 이부분을 어떻게 활용하느냐에 따라 달라진다.
	//Camera::SetTarget(mCuphead);

	/*Monster* monster = new Monster();
	AddGameObject(monster, eLayerType::Monster);

	monster = new Monster();
	AddGameObject(monster, eLayerType::Monster);*/
	// CollistionManager에 넘길 때 Player는 left Monster는 Right
	// left가 2 right가 1
	/*CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
	Scene::Initialize();*/
}

void PlayScene::Update()
{
	if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Title);
	}

	Scene::Update();
}

void PlayScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void PlayScene::Release()
{
	Scene::Release();
}

void PlayScene::OnEnter()
{
	//CollisionManager::SetLayer(eLayerType::Player, eLayerType::Player, true);
	
}

void PlayScene::OnExit()
{
}
