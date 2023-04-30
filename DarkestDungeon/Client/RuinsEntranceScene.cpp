#include "RuinsEntranceScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "Transform.h"
#include "Object.h"

//BG
#include "RuinsEntranceBG.h"
//UI
#include "InfoUIBG.h"
#include "HeroInfoUIBG.h"
#include "DGMapBG.h"
#include "DGInventoryBG.h"


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
	object::Instantiate<DGMapBG>(eLayerType::UI1);

}

void RuinsEntranceScene::Update()
{
	Scene::Update();
	Vector2 MousePos = Input::GetMousePos();
	// Map
	if ((MousePos.x > 1316 && MousePos.x < 1392) && (MousePos.y > 717 && MousePos.y < 821))
	{
		if (Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			object::Instantiate<DGMapBG>(eLayerType::UI1);
		}
	}
	//Inventory
	if ((MousePos.x > 1316 && MousePos.x < 1392) && (MousePos.y > 830 && MousePos.y < 874))
	{
		if (Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			object::Instantiate<DGInventoryBG>(eLayerType::UI1);
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
}

void RuinsEntranceScene::OnExit()
{
}
