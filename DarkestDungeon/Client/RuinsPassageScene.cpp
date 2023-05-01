#include "RuinsPassageScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "Transform.h"
#include "Object.h"
//#include "Camera.h"

//BG
#include"RuinsPassageBG.h"

//UI
#include "InfoUIBG.h"
#include "HeroInfoUIBG.h"
#include "DGMapBG.h"
#include "DGInventoryBG.h"

//Player
#include "Crusader.h"

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

	//PlayerInfoUI
	mCrusaderInfoUI = object::Instantiate<CrusaderInfoUI>(eLayerType::UI2);


	//Camera::SetTarget(mCrusader);


}

void RuinsPassageScene::Update()
{
	Scene::Update();
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
}

void RuinsPassageScene::OnExit()
{
}
