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
	object::Instantiate<DGMapBG>(eLayerType::UI1);

}

void RuinsEntranceScene::Update()
{
	Scene::Update();
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
