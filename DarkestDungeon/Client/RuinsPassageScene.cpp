#include "RuinsPassageScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "Transform.h"
#include "Object.h"
#include "Camera.h"
#include "CollisionManager.h"

//BG
#include"RuinsPassageBG.h"

//UI
#include "InfoUIBG.h"
#include "HeroInfoUIBG.h"
#include "DGMapBG.h"
#include "DGInventoryBG.h"

//Player
//Player
#include "Crusader.h"
#include "HighwayMan.h"
#include "PlagueDoctor.h"
#include "Vestal.h"

//Player Info UI
#include "CrusaderInfoUI.h"


RuinsPassageScene::RuinsPassageScene()
{
}

RuinsPassageScene::~RuinsPassageScene()
{
}

void RuinsPassageScene::Initialize()
{
	Scene::Initialize();
	//BG
	object::Instantiate<RuinsPassageBG>(eLayerType::BackGround);
	object::Instantiate<InfoUIBG>(eLayerType::BackGround);

	//UI
	object::Instantiate<HeroInfoUIBG>(eLayerType::UI1);
	//Map
	//mDGInventoryBG = object::Instantiate<DGInventoryBG>(eLayerType::UI1);
	mDGMapBG = object::Instantiate<DGMapBG>(eLayerType::UI1);

	//Player
	mCrusader = object::Instantiate<Crusader>(eLayerType::Player);
	mHighwayMan = object::Instantiate<HighwayMan>(eLayerType::Player);
	mPlagueDoctor = object::Instantiate<PlagueDoctor>(eLayerType::Player);
	mVestal = object::Instantiate<Vestal>(eLayerType::Player);


	//PlayerInfoUI
	mCrusaderInfoUI = object::Instantiate<CrusaderInfoUI>(eLayerType::UI2);

}

void RuinsPassageScene::Update()
{
	Scene::Update();
	// ī�޶� �ִ� �̵��Ÿ��� �Ѿ�� ����
	Camera::SetTarget(mCrusader);
	Camera::SetMinX(550.0f);
	Camera::SetMaxX(2800.0f);

	Vector2 MousePos = Input::GetMousePos();

	if (Input::GetKeyDown(eKeyCode::W))
	{
		SceneManager::LoadScene(eSceneType::RuinsBattle);
	}

	// Map
	if ((MousePos.x > 1316 && MousePos.x < 1392) && (MousePos.y > 717 && MousePos.y < 821))
	{
		if (Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			mDGMapBG = object::Instantiate<DGMapBG>(eLayerType::UI1);
			// InventoryUI �����ֱ�
			object::Destory(mDGInventoryBG);
		}
	}
	//Inventory
	if ((MousePos.x > 1316 && MousePos.x < 1392) && (MousePos.y > 830 && MousePos.y < 874))
	{
		if (Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			mDGInventoryBG = object::Instantiate<DGInventoryBG>(eLayerType::UI1);
			// MapUI �����ֱ�
			object::Destory(mDGMapBG);
		}

	}
}

void RuinsPassageScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void RuinsPassageScene::Release()
{
	Scene::Release();
}

void RuinsPassageScene::OnEnter()
{
	Scene::OnEnter();

}

void RuinsPassageScene::OnExit()
{
	Scene::OnExit();
	CollisionManager::Clear();
}
