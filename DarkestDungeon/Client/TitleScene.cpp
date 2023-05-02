#include "TitleScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "Transform.h"
#include "Object.h"
#include "Sound.h"
#include "Resources.h"

#include "Logo.h"
#include "TitleBG.h"
#include "TitleHouse.h"
#include "StartButton.h"

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Initialize()
{
	Scene::Initialize();
	
	// 사운드
	Titletheme = Resources::Load<Sound>(L"TitleTheme", L"..\\Resources\\Sound\\BGM\\title_theme.wav");
	Titletheme->Play(true);
	// 배경
	object::Instantiate<TitleBG>(eLayerType::BackGround);
	// house
	object::Instantiate<TitleHouse>(eLayerType::Shadow);
	// Logo
	object::Instantiate<Logo>(eLayerType::UI1);
	// startButton
	object::Instantiate<StartButton>(eLayerType::UI1);
}

void TitleScene::Update()
{
	Scene::Update();

	Vector2 MousePos = Input::GetMousePos();

	if ((MousePos.x > 650 && MousePos.x < 950) && (MousePos.y > 780 && MousePos.y < 850))
	{
		if (Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			SceneManager::LoadScene(eSceneType::Town);
			
		}
	}
	
}

void TitleScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void TitleScene::Release()
{
	Scene::Release();
}

void TitleScene::OnEnter()
{
	Scene::OnEnter();
	Titletheme->Play(true);
}

void TitleScene::OnExit()
{
	Scene::OnExit();
	Titletheme->Stop(true);
}
