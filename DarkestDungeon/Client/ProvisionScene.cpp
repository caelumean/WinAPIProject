#include "ProvisionScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "Transform.h"
#include "Object.h"
#include "Sound.h"
#include "Resources.h"

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
	Towntheme = Resources::Load<Sound>(L"TownTheme", L"..\\Resources\\Sound\\BGM\\Town.wav");
	//Towntheme->Play(true);
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
		if (Input::GetKeyState(eKeyCode::LBUTTON) == eKeyState::Down)
		{
			Towntheme->Stop(true);
			SceneManager::LoadScene(eSceneType::RuinsEntrance);
		}
	}
	if (Input::GetKeyState(eKeyCode::ESC) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::SelectDugeon);
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
	//Towntheme->Play(true);
	Scene::OnEnter();
}

void ProvisionScene::OnExit()
{
	Towntheme->Stop(true);
	Scene::OnExit();
}
