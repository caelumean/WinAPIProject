#include "RuinsEntranceScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "Transform.h"
#include "Camera.h"
#include "Object.h"

//BG
#include "RuinsEntranceBG.h"
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


RuinsEntranceScene::RuinsEntranceScene()
{
}

RuinsEntranceScene::~RuinsEntranceScene()
{
}

void RuinsEntranceScene::Initialize()
{
	Scene::Initialize();
	//BG
	object::Instantiate<RuinsEntranceBG>(eLayerType::BackGround);
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

void RuinsEntranceScene::Update()
{
	Scene::Update();
	Camera::SetTarget(mCrusader);
	Camera::SetMinX(500.0f);
	Camera::SetMaxX(700.0f);

	Vector2 MousePos = Input::GetMousePos();

	if (Input::GetKeyDown(eKeyCode::W))
	{
		SceneManager::LoadScene(eSceneType::RuinsPassage);
	}


	// Map
	if ((MousePos.x > 1316 && MousePos.x < 1392) && (MousePos.y > 717 && MousePos.y < 821))
	{
		if (Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			mDGMapBG = object::Instantiate<DGMapBG>(eLayerType::UI1);
			// InventoryUI 지워주기
			object::Destory(mDGInventoryBG);
		}
	}
	//Inventory
	if ((MousePos.x > 1316 && MousePos.x < 1392) && (MousePos.y > 830 && MousePos.y < 874))
	{
		if (Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			mDGInventoryBG = object::Instantiate<DGInventoryBG>(eLayerType::UI1);
			// MapUI 지워주기
			object::Destory(mDGMapBG);
		}

	}

	//PlayerInfoUI
	if ((MousePos.x > 255 && MousePos.x < 338) && (MousePos.y > 370 && MousePos.y < 597))
	{
		if (Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			mVestalInfoUI = object::Instantiate<VestalInfoUI>(eLayerType::UI2);
			isVestalInfoUI = true;

			// 닥터
			if (isPlagueDoctorInfoUI)
			{
				isPlagueDoctorInfoUI = false;
				object::Destory(mPlagueDoctorInfoUI);
			}
			//하이웨이맨
			else if (isHighwayManInfoUI)
			{
				isHighwayManInfoUI = false;
				object::Destory(mHighwayManInfoUI);
			}
			//크루세이더
			else if (ismCrusaderInfoUI)
			{
				ismCrusaderInfoUI = false;
				object::Destory(mCrusaderInfoUI);
			}
		}
	}
	if ((MousePos.x > 395 && MousePos.x < 487) && (MousePos.y > 370 && MousePos.y < 597))
	{
		if (Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			mPlagueDoctorInfoUI = object::Instantiate<PlagueDoctorInfoUI>(eLayerType::UI2);
			isPlagueDoctorInfoUI = true;

			// 성녀
			if (isVestalInfoUI)
			{
				isVestalInfoUI = false;
				object::Destory(mVestalInfoUI);
			}
			//하이웨이맨
			else if (isHighwayManInfoUI)
			{
				isHighwayManInfoUI = false;
				object::Destory(mHighwayManInfoUI);
			}
			//크루세이더
			else if (ismCrusaderInfoUI)
			{
				ismCrusaderInfoUI = false;
				object::Destory(mCrusaderInfoUI);
			}
		}
		
	}
	if ((MousePos.x > 525 && MousePos.x < 630) && (MousePos.y > 355 && MousePos.y < 597))
	{
		if (Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			mHighwayManInfoUI = object::Instantiate<HighwayManInfoUI>(eLayerType::UI2);
			// 성녀
			if (isVestalInfoUI)
			{
				isVestalInfoUI = false;
				object::Destory(mVestalInfoUI);
			}
			// 닥터
			else if (isPlagueDoctorInfoUI)
			{
				isPlagueDoctorInfoUI = false;
				object::Destory(mPlagueDoctorInfoUI);
			}
			//크루세이더
			else if (ismCrusaderInfoUI)
			{
				ismCrusaderInfoUI = false;
				object::Destory(mCrusaderInfoUI);
			}
		}
	}
	if ((MousePos.x > 672 && MousePos.x < 772) && (MousePos.y > 352 && MousePos.y < 597))
	{
		if (Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			mCrusaderInfoUI = object::Instantiate<CrusaderInfoUI>(eLayerType::UI2);
			// 성녀
			if (isVestalInfoUI)
			{
				isVestalInfoUI = false;
				object::Destory(mVestalInfoUI);
			}
			// 닥터
			else if (isPlagueDoctorInfoUI)
			{
				isPlagueDoctorInfoUI = false;
				object::Destory(mPlagueDoctorInfoUI);
			}
			//하이웨이맨
			else if (isHighwayManInfoUI)
			{
				isHighwayManInfoUI = false;
				object::Destory(mHighwayManInfoUI);
			}
		}
	}
}

void RuinsEntranceScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void RuinsEntranceScene::Release()
{
	Scene::Release();
}

void RuinsEntranceScene::OnEnter()
{
	Scene::OnEnter();
}

void RuinsEntranceScene::OnExit()
{
	Scene::OnExit();
}
