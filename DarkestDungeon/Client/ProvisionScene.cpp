#include "ProvisionScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "Transform.h"
#include "Object.h"

//BG
#include "ProvisionBG.h"
#include "ProvisionNPC.h"
#include "ProvisionNPCBG.h"
//UI
#include "TownCommonUI1.h"
#include "TripButton.h"
//#include "ProvisionInvetory.h"


ProvisionScene::ProvisionScene()
{
}

ProvisionScene::~ProvisionScene()
{
}

void ProvisionScene::Initialize()
{
	Scene::Initialize();
	//BG
	object::Instantiate<ProvisionBG>(eLayerType::BackGround);
	object::Instantiate<ProvisionNPCBG>(eLayerType::Shadow);
	object::Instantiate<ProvisionNPC>(eLayerType::NPC);

	//UI
	object::Instantiate<TownCommonUI1>(eLayerType::UI1);
	//object::Instantiate<ProvisionInvetory>(eLayerType::UI1);
	object::Instantiate<TripButton>(eLayerType::UI2);

}

void ProvisionScene::Update()
{
	Scene::Update();
	Vector2 MousePos = Input::GetMousePos();

	// Trip Button
	if ((MousePos.x > 680 && MousePos.x < 980) && (MousePos.y > 803 && MousePos.y < 850))
	{
		if (Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			SceneManager::LoadScene(eSceneType::RuinsEntrance);
		}
	}
}

void ProvisionScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void ProvisionScene::Release()
{
	Scene::Release();
}

void ProvisionScene::OnEnter()
{
	Scene::OnEnter();
}

void ProvisionScene::OnExit()
{
	Scene::OnExit();
}
