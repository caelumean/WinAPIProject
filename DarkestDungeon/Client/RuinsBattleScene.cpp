#include "RuinsBattleScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "Transform.h"
#include "Object.h"

//UI
#include "InfoUIBG.h"
#include "HeroInfoUIBG.h"
#include "DGMapBG.h"
#include "DGInventoryBG.h"

//Player
#include "Crusader.h"
#include "HighwayMan.h"
#include "PlagueDoctor.h"
#include "Vestal.h"

//Player Info UI
#include "CrusaderInfoUI.h"
#include "HighwayManInfoUI.h"
#include "PlagueDoctorInfoUI.h"
#include "VestalInfoUI.h"

RuinsBattleScene::RuinsBattleScene()
{
}

RuinsBattleScene::~RuinsBattleScene()
{
}

void RuinsBattleScene::Initialize()
{
	Scene::Initialize();
	//BG
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

}

void RuinsBattleScene::Update()
{
	Scene::Update();
	Vector2 MousePos = Input::GetMousePos();

	// Map
	if ((MousePos.x > 1316 && MousePos.x < 1392) && (MousePos.y > 717 && MousePos.y < 821))
	{
		if (Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			mDGMapBG = object::Instantiate<DGMapBG>(eLayerType::UI1);
			// InventoryUI 瘤况林扁
			object::Destory(mDGInventoryBG);
		}
	}
	//Inventory
	if ((MousePos.x > 1316 && MousePos.x < 1392) && (MousePos.y > 830 && MousePos.y < 874))
	{
		if (Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			mDGInventoryBG = object::Instantiate<DGInventoryBG>(eLayerType::UI1);
			// MapUI 瘤况林扁
			object::Destory(mDGMapBG);
		}

	}
}

void RuinsBattleScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void RuinsBattleScene::Release()
{
	Scene::Release();
}

void RuinsBattleScene::OnEnter()
{
	Scene::OnEnter();
}

void RuinsBattleScene::OnExit()
{
	Scene::OnExit();
}
