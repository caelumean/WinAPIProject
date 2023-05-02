#include "RuinsEntranceScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "Transform.h"
#include "Camera.h"
#include "Object.h"
#include "Sound.h"
#include "Resources.h"

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

//SelectUI
#include "SelectbarUI.h"

RuinsEntranceScene::RuinsEntranceScene()
{
}

RuinsEntranceScene::~RuinsEntranceScene()
{
}

void RuinsEntranceScene::Initialize()
{
	Scene::Initialize();
	//사운드
	Ruins = Resources::Load<Sound>(L"Ruins", L"..\\Resources\\Sound\\BGM\\ruins_base.wav");
	Ruins->Play(true);
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
	Camera::SetMinX(800.0f);
	Camera::SetMaxX(800.0f);

	Vector2 MousePos = Input::GetMousePos();

	if (Input::GetKeyDown(eKeyCode::W))
	{
		SceneManager::LoadScene(eSceneType::RuinsPassage);
	}


	// Map
	if ((MousePos.x > 1316 && MousePos.x < 1392) && (MousePos.y > 717 && MousePos.y < 821))
	{
		if (Input::GetKeyState(eKeyCode::LBUTTON) == eKeyState::Down)
		{
			mDGMapBG = object::Instantiate<DGMapBG>(eLayerType::UI1);
			// InventoryUI 지워주기
			object::Destory(mDGInventoryBG);
		}
	}
	//Inventory
	if ((MousePos.x > 1316 && MousePos.x < 1392) && (MousePos.y > 830 && MousePos.y < 874))
	{
		if (Input::GetKeyState(eKeyCode::LBUTTON) == eKeyState::Down)
		{
			mDGInventoryBG = object::Instantiate<DGInventoryBG>(eLayerType::UI1);
			// MapUI 지워주기
			object::Destory(mDGMapBG);
		}

	}

	//PlayerInfoUI
	//성녀
	if ((MousePos.x > 149 && MousePos.x < 240) && (MousePos.y > 374 && MousePos.y < 597))
	{
		if (Input::GetKeyState(eKeyCode::LBUTTON) == eKeyState::Down)
		{
			mVestalInfoUI = object::Instantiate<VestalInfoUI>(eLayerType::UI2);
			mVestalSelectUI = object::Instantiate<SelectbarUI>(Vector2(274.0f, 665.0f), eLayerType::UI2);
			isVestalInfoUI = true;

			// 닥터
			if (isPlagueDoctorInfoUI)
			{
				object::Destory(mPlagueDoctorInfoUI);
				object::Destory(mPlagueDoctorSelectUI);
				isPlagueDoctorInfoUI = false;
			}
			//하이웨이맨
			if (isHighwayManInfoUI)
			{
				object::Destory(mHighwayManInfoUI);
				object::Destory(mHighwayManSelectUI);
				isHighwayManInfoUI = false;
			}
			//크루세이더
			if (ismCrusaderInfoUI)
			{
				object::Destory(mCrusaderInfoUI);
				object::Destory(mCrusaderSelectUI);
				ismCrusaderInfoUI = false;
			}
		}
	}
	//닥터 
	if ((MousePos.x > 285 && MousePos.x < 385) && (MousePos.y > 377 && MousePos.y < 597))
	{
		if (Input::GetKeyState(eKeyCode::LBUTTON) == eKeyState::Down)
		{
			mPlagueDoctorInfoUI = object::Instantiate<PlagueDoctorInfoUI>(eLayerType::UI2);
			mPlagueDoctorSelectUI = object::Instantiate<SelectbarUI>(Vector2(414.0f, 665.0f), eLayerType::UI2);
			isPlagueDoctorInfoUI = true;

			// 성녀
			if (isVestalInfoUI)
			{
				object::Destory(mVestalInfoUI);
				object::Destory(mVestalSelectUI);
				isVestalInfoUI = false;
			}
			//하이웨이맨
			if (isHighwayManInfoUI)
			{
				object::Destory(mHighwayManInfoUI);
				object::Destory(mHighwayManSelectUI);
				isHighwayManInfoUI = false;
			}
			//크루세이더
			if (ismCrusaderInfoUI)
			{
				object::Destory(mCrusaderInfoUI);
				object::Destory(mCrusaderSelectUI);
				ismCrusaderInfoUI = false;
			}
		}

	}
	//하이웨이맨
	if ((MousePos.x > 430 && MousePos.x < 522) && (MousePos.y > 365 && MousePos.y < 597))
	{
		if (Input::GetKeyState(eKeyCode::LBUTTON) == eKeyState::Down)
		{
			mHighwayManInfoUI = object::Instantiate<HighwayManInfoUI>(eLayerType::UI2);
			mHighwayManSelectUI = object::Instantiate<SelectbarUI>(Vector2(565.0f, 665.0f), eLayerType::UI2);
			isHighwayManInfoUI = true;
			// 성녀
			if (isVestalInfoUI)
			{
				object::Destory(mVestalInfoUI);
				object::Destory(mVestalSelectUI);
				isVestalInfoUI = false;
			}

			// 닥터
			if (isPlagueDoctorInfoUI)
			{
				object::Destory(mPlagueDoctorInfoUI);
				object::Destory(mPlagueDoctorSelectUI);
				isPlagueDoctorInfoUI = false;
			}
			//크루세이더
			if (ismCrusaderInfoUI)
			{
				object::Destory(mCrusaderInfoUI);
				object::Destory(mCrusaderSelectUI);
				ismCrusaderInfoUI = false;
			}
		}
	}
	// 성기사
	if ((MousePos.x > 556 && MousePos.x < 670) && (MousePos.y > 370 && MousePos.y < 597))
	{
		if (Input::GetKeyState(eKeyCode::LBUTTON) == eKeyState::Down)
		{
			mCrusaderInfoUI = object::Instantiate<CrusaderInfoUI>(eLayerType::UI2);
			mCrusaderSelectUI = object::Instantiate<SelectbarUI>(Vector2(705.0f, 665.0f), eLayerType::UI2);
			ismCrusaderInfoUI = true;
			// 성녀
			if (isVestalInfoUI)
			{
				object::Destory(mVestalInfoUI);
				object::Destory(mVestalSelectUI);
				isVestalInfoUI = false;
			}
			// 닥터
			if (isPlagueDoctorInfoUI)
			{
				object::Destory(mPlagueDoctorInfoUI);
				object::Destory(mPlagueDoctorSelectUI);
				isPlagueDoctorInfoUI = false;
			}
			//하이웨이맨
			if (isHighwayManInfoUI)
			{
				object::Destory(mHighwayManInfoUI);
				object::Destory(mHighwayManSelectUI);
				isHighwayManInfoUI = false;
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
	Ruins->Play(true);
	Scene::OnEnter();
}

void RuinsEntranceScene::OnExit()
{
	Ruins->Stop(true);
	Scene::OnExit();
}
