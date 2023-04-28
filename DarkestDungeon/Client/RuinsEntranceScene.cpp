#include "RuinsEntranceScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "Transform.h"
#include "Object.h"

//BG
#include "RuinsBG.h"

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
	object::Instantiate<RuinsBG>(eLayerType::BackGround);
}

void RuinsEntranceScene::Update()
{
}

void RuinsEntranceScene::Render(HDC hdc)
{
}

void RuinsEntranceScene::Release()
{
}

void RuinsEntranceScene::OnEnter()
{
}

void RuinsEntranceScene::OnExit()
{
}
