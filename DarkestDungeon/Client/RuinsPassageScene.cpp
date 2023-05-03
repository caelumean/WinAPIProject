#include "RuinsPassageScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "Transform.h"
#include "Object.h"
#include "Camera.h"
#include "CollisionManager.h"
#include "Sound.h"
#include "Resources.h"

//BG
#include "RuinsPassageBG.h"
#include "EntranceDoor.h"
#include "BattleDoor.h"

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

//DungeonObj
#include "DiscardedPack.h"
#include "StackofBooks.h"


RuinsPassageScene::RuinsPassageScene()
{
}

RuinsPassageScene::~RuinsPassageScene()
{
}

void RuinsPassageScene::Initialize()
{
	Scene::Initialize();
	//사운드
	Ruins = Resources::Load<Sound>(L"Ruins", L"..\\Resources\\Sound\\BGM\\ruins_base.wav");
	Ruins->Play(true);
	//BG
	object::Instantiate<RuinsPassageBG>(eLayerType::BackGround);
	object::Instantiate<InfoUIBG>(eLayerType::BackGround);
	object::Instantiate<EntranceDoor>(eLayerType::EntranceDoor);
	object::Instantiate<BattleDoor>(eLayerType::BattleRoomDoor);

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

	//DungeonObk
	object::Instantiate<DiscardedPack>(eLayerType::DungeonObj);
	object::Instantiate<StackofBooks>(eLayerType::DungeonObj);
}

void RuinsPassageScene::Update()
{
	Scene::Update();
	// 카메라 최대 이동거리를 넘어가면 조정
	Camera::SetTarget(mCrusader);
	Camera::SetMinX(660.0f);
	Camera::SetMaxX(2800.0f);

	Vector2 MousePos = Input::GetMousePos();

	if (Input::GetKeyDown(eKeyCode::W))
	{
		SceneManager::LoadScene(eSceneType::RuinsBattle);
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
	if ((MousePos.x > 132 && MousePos.x < 245) && (MousePos.y > 370 && MousePos.y < 597))
	{
		if (Input::GetKeyState(eKeyCode::LBUTTON) == eKeyState::Down)
		{
			mVestalInfoUI = object::Instantiate<VestalInfoUI>(eLayerType::UI2);
			isVestalInfoUI = true;

			// 닥터
			if (isPlagueDoctorInfoUI)
			{
				object::Destory(mPlagueDoctorInfoUI);
				isPlagueDoctorInfoUI = false;
			}
			//하이웨이맨
			if (isHighwayManInfoUI)
			{
				object::Destory(mHighwayManInfoUI);
				isHighwayManInfoUI = false;
			}
			//크루세이더
			if (ismCrusaderInfoUI)
			{
				object::Destory(mCrusaderInfoUI);
				ismCrusaderInfoUI = false;
			}
		}
	}
	//닥터 
	if ((MousePos.x > 278 && MousePos.x < 387) && (MousePos.y > 375 && MousePos.y < 597))
	{
		if (Input::GetKeyState(eKeyCode::LBUTTON) == eKeyState::Down)
		{
			mPlagueDoctorInfoUI = object::Instantiate<PlagueDoctorInfoUI>(eLayerType::UI2);
			isPlagueDoctorInfoUI = true;

			// 성녀
			if (isVestalInfoUI)
			{
				object::Destory(mVestalInfoUI);
				isVestalInfoUI = false;
			}
			//하이웨이맨
			if (isHighwayManInfoUI)
			{
				object::Destory(mHighwayManInfoUI);				
				isHighwayManInfoUI = false;
			}
			//크루세이더
			if (ismCrusaderInfoUI)
			{
				object::Destory(mCrusaderInfoUI);				
				ismCrusaderInfoUI = false;
			}
		}

	}
	//하이웨이맨
	if ((MousePos.x > 430 && MousePos.x < 527) && (MousePos.y > 355 && MousePos.y < 597))
	{
		if (Input::GetKeyState(eKeyCode::LBUTTON) == eKeyState::Down)
		{
			mHighwayManInfoUI = object::Instantiate<HighwayManInfoUI>(eLayerType::UI2);	
			isHighwayManInfoUI = true;
			// 성녀
			if (isVestalInfoUI)
			{
				object::Destory(mVestalInfoUI);
				isVestalInfoUI = false;
			}

			// 닥터
			if (isPlagueDoctorInfoUI)
			{
				object::Destory(mPlagueDoctorInfoUI);
				isPlagueDoctorInfoUI = false;
			}
			//크루세이더
			if (ismCrusaderInfoUI)
			{
				object::Destory(mCrusaderInfoUI);
				ismCrusaderInfoUI = false;
			}
		}
	}
	// 성기사
	if ((MousePos.x > 570 && MousePos.x < 670) && (MousePos.y > 352 && MousePos.y < 597))
	{
		if (Input::GetKeyState(eKeyCode::LBUTTON) == eKeyState::Down)
		{
			mCrusaderInfoUI = object::Instantiate<CrusaderInfoUI>(eLayerType::UI2);
			ismCrusaderInfoUI = true;
			// 성녀
			if (isVestalInfoUI)
			{
				object::Destory(mVestalInfoUI);
				isVestalInfoUI = false;
			}
			// 닥터
			if (isPlagueDoctorInfoUI)
			{
				object::Destory(mPlagueDoctorInfoUI);
				isPlagueDoctorInfoUI = false;
			}
			//하이웨이맨
			if (isHighwayManInfoUI)
			{
				object::Destory(mHighwayManInfoUI);
				isHighwayManInfoUI = false;
			}
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
	Ruins->Play(true);
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::BattleRoomDoor, true);

}

void RuinsPassageScene::OnExit()
{
	Scene::OnExit();
	Ruins->Stop(true);
	CollisionManager::Clear();
}
