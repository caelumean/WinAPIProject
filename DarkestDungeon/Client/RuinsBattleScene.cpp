#include "RuinsBattleScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "Transform.h"
#include "Camera.h"
#include "Object.h"
#include "Animator.h"
#include "Time.h"
#include "Sound.h"
#include "Resources.h"

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
#include "CrusaderBattleInfoUI.h"
#include "HighwayManInfoUI.h"
#include "PlagueDoctorInfoUI.h"
#include "VestalInfoUI.h"

// Player Attak and Denfend
#include "CrusaderSword.h"
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
#include "BattleSelectbarUI.h"

//Monster
#include "BoneDefender.h"
#include "BoneSoldier.h"
#include "BoneCourtier.h"
#include "BoneArbalest.h"


RuinsBattleScene::RuinsBattleScene()
	:HeroMember(4)
	,MonsterMember(4)
	,mTime(0.0f)
	, mEndTime(0.12f)
	,End(false)
{
}

RuinsBattleScene::~RuinsBattleScene()
{
}

void RuinsBattleScene::Initialize()
{
	Scene::Initialize();
	Scene* scene = SceneManager::GetActiveScene();

	CombatTheme = Resources::Load<Sound>(L"Combat", L"..\\Resources\\Sound\\BGM\\Combat.wav");
	
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
	Scene::Update();

	Vector2 MousePos = Input::GetMousePos();
	
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
	if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}
	if (!End)
	{
		Crusaderturn = true;
		// 크루세이더 턴
		if (Crusaderturn == true)
		{
			mCrusaderInfoUI = object::Instantiate<CrusaderBattleInfoUI>(eLayerType::UI2);

			//스킬 1번 클릭하고 
			if ((MousePos.x > 439 && MousePos.x < 487) && (MousePos.y > 676 && MousePos.y < 725) && (Input::GetKeyState(eKeyCode::LBUTTON) == eKeyState::Down))
			{
				//mCrusaderSword = object::Instantiate<CrusaderSword>(eLayerType::UI2);
				isSkillClick = true;

				if (isSkillClick)
				{
					// 첫번째 몬스터 클릭
					if ((MousePos.x > 900 && MousePos.x < 993) && (MousePos.y > 363 && MousePos.y < 593) && (Input::GetKeyDown(eKeyCode::LBUTTON)))
					{

						// 스킬이미지 
						mCrusaderSword = object::Instantiate<CrusaderSword>(eLayerType::UI2);

						//Crusaderturn = false;
						//HiwayManturn = true;


					}
				}
				
			}
			// 크루세이더 이미지 다 삭제
			if (HiwayManturn == true)
			{	
				// 테스트
				mCrusaderDefend = object::Instantiate<CrusaderDefend>(eLayerType::UI2);
				//흐음?
				object::Destory(mCrusaderSword);
				object::Destory(mCrusaderInfoUI);
			}
			
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
	CombatTheme->Play(true);
	Scene::OnEnter();
	Camera::SetTarget(mCrusader);
	Camera::SetMinX(800.0f);
	Camera::SetMaxX(800.0f);
	Camera::SetMinY(450.0f);
	Camera::SetMaxY(450.0f);
}

void RuinsBattleScene::OnExit()
{
	CombatTheme->Stop(true);
	Scene::OnExit();
}
