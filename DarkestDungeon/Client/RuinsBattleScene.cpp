#include "RuinsBattleScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "Transform.h"
//#include "Camera.h"
#include "Object.h"
#include "Animator.h"
#include "Time.h"

//BG
#include "RuinsBattleBG.h"
//UI
#include "InfoUIBG.h"
#include "HeroInfoUIBG.h"
#include "DGMapBG.h"
#include "DGInventoryBG.h"

//Player
#include "CrusaderCombat.h"
#include "HighwayManCombat.h"
#include "PlagueDoctorCombat.h"
#include "VestalCombat.h"

//Player Info UI
#include "CrusaderInfoUI.h"
#include "HighwayManInfoUI.h"
#include "PlagueDoctorInfoUI.h"
#include "VestalInfoUI.h"

// Player Attak and Denfend
#include "CrusaderDefend.h"
//Player HP Stress UI
#include "CrusaderHPbar.h"
#include "HighwayManHPbar.h"
#include "PlagueDoctorHPbar.h"
#include "VestalHPbar.h"
#include "CrusaderStressbar.h"
#include "HighwayStressbar.h"
#include "PlagueDoctorStressbar.h"
#include "VestalStressbar.h"

//SelectUI
#include "SelectbarUI.h"

//Monster
#include "BoneDefender.h"
#include "BoneSoldier.h"
#include "BoneCourtier.h"
#include "BoneArbalest.h"


RuinsBattleScene::RuinsBattleScene()
	:HeroMember(4)
	,MonsterMember(4)
	, mTime(0.0f)
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
	mCrusader = object::Instantiate<CrusaderCombat>(eLayerType::Player);
	mHighwayMan = object::Instantiate<HighwayManCombat>(eLayerType::Player);
	mPlagueDoctor = object::Instantiate<PlagueDoctorCombat>(eLayerType::Player);
	mVestal = object::Instantiate<VestalCombat>(eLayerType::Player);

	//Player HP Stress UI
	object::Instantiate<CrusaderHPbar>(Vector2(580.0f, 630.0f), eLayerType::UI2);
	object::Instantiate<HighwayManHPbar>(Vector2(440.0f, 630.0f), eLayerType::UI2);
	object::Instantiate<PlagueDoctorHPbar>(Vector2(290.0f, 630.0f), eLayerType::UI2);
	object::Instantiate<VestalHPbar>(Vector2(150.0f, 630.0f), eLayerType::UI2);

	object::Instantiate<CrusaderStressbar>(Vector2(615.0f, 645.0f), eLayerType::UI2);
	object::Instantiate<HighwayStressbar>(Vector2(475.0f, 645.0f), eLayerType::UI2);
	object::Instantiate<PlagueDoctorStressbar>(Vector2(325.0f, 645.0f), eLayerType::UI2);
	object::Instantiate<VestalStressbar>(Vector2(185.0f, 645.0f), eLayerType::UI2);

	//Monster
	mBoneDefender = object::Instantiate<BoneDefender>(Vector2(1050.0f, 860.0f), eLayerType::Monster);
	mBoneSoldier = object::Instantiate<BoneSoldier>(Vector2(1180.0f, 863.0f), eLayerType::Monster);
	mBoneCourtier = object::Instantiate<BoneCourtier>(Vector2(1310.0f, 851.0f), eLayerType::Monster);
	mBoneArbalest = object::Instantiate<BoneArbalest>(Vector2(1350.0f, 650.0f), eLayerType::Monster);

	//object::Instantiate<CrusaderDefend>(eLayerType::UI2);
}

void RuinsBattleScene::Update()
{
	
	/*Camera::SetTarget(mCrusader);
	Camera::SetMinX(800.0f);
	Camera::SetMaxX(800.0f);*/
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

	mTime += Time::DeltaTime();

	// 农风技捞歹 剁快扁
	if (mTime > 1.0f)
	{
		mCrusaderInfoUI = object::Instantiate<CrusaderInfoUI>(eLayerType::UI2);
	}
	else if (mTime < 0.5f)
	{
		object::Destory(mCrusaderInfoUI);
	}
	//object::Destory(mCrusaderInfoUI);
	/*if (mTime > 0.05f)
	{
		object::Destory(mCrusaderInfoUI);

	}*/
	
	
	
	//mPlagueDoctorInfoUI = object::Instantiate<PlagueDoctorInfoUI>(eLayerType::UI2);
	//mPlagueDoctorSelectUI = object::Instantiate<SelectbarUI>(Vector2(414.0f, 665.0f), eLayerType::UI2);
	Scene::Update();
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
