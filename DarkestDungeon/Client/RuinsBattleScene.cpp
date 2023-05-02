#include "RuinsBattleScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "Transform.h"
#include "Camera.h"
#include "Object.h"

//BG
#include "RuinsBattleBG.h"
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

//Player HP Stress UI
#include "CrusaderHPbar.h"
#include "HighwayManHPbar.h"
#include "PlagueDoctorHPbar.h"
#include "VestalHPbar.h"
#include "CrusaderStressbar.h"
#include "HighwayStressbar.h"
#include "PlagueDoctorStressbar.h"
#include "VestalStressbar.h"


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
	object::Instantiate<RuinsBattleBG>(eLayerType::BackGround);
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

	//Player HP Stress UI
	object::Instantiate<CrusaderHPbar>(Vector2(580.0f, 630.0f), eLayerType::UI2);
	object::Instantiate<HighwayManHPbar>(Vector2(440.0f, 630.0f), eLayerType::UI2);
	object::Instantiate<PlagueDoctorHPbar>(Vector2(290.0f, 630.0f), eLayerType::UI2);
	object::Instantiate<VestalHPbar>(Vector2(150.0f, 630.0f), eLayerType::UI2);

	object::Instantiate<CrusaderStressbar>(Vector2(615.0f, 645.0f), eLayerType::UI2);
	object::Instantiate<HighwayStressbar>(Vector2(475.0f, 645.0f), eLayerType::UI2);
	object::Instantiate<PlagueDoctorStressbar>(Vector2(325.0f, 645.0f), eLayerType::UI2);
	object::Instantiate<VestalStressbar>(Vector2(185.0f, 645.0f), eLayerType::UI2);

}

void RuinsBattleScene::Update()
{
	Scene::Update();
	Camera::SetTarget(mCrusader);
	Camera::SetMinX(800.0f);
	Camera::SetMaxX(800.0f);
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
