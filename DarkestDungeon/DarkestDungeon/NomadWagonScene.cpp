#include "NomadWagonScene.h"
#include "SceneManager.h"
#include "Input.h"

//BG
#include "NomadWagonBG.h"
#include "NomadWagonNPCBG.h"
#include "NomadWagonNPC.h"

//UI
#include "ProgressionBar.h"
#include "Namesplate.h"

NomadWagonScene::NomadWagonScene()
{
}

NomadWagonScene::~NomadWagonScene()
{
}

void NomadWagonScene::Initialize()
{
	//BG
	mNomadWagonBG = new NomadWagonBG();
	AddGameObeject(mNomadWagonBG, eLayerType::BackGround);
	mNomadWagonNPCBG = new NomadWagonNPCBG();
	AddGameObeject(mNomadWagonNPCBG, eLayerType::Shadow);
	mNomadWagonNPC = new NomadWagonNPC();
	AddGameObeject(mNomadWagonNPC, eLayerType::NPC);

	//UI
	mProgressionBar = new ProgressionBar();
	AddGameObeject(mProgressionBar, eLayerType::UI1);
	mNamesplate = new Namesplate();
	AddGameObeject(mNamesplate, eLayerType::Sky);

	Scene::Initialize();
}

void NomadWagonScene::Update()
{
	if (Input::GetKeyState(eKeyCode::X) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Town);
	}

	Scene::Update();
}

void NomadWagonScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void NomadWagonScene::Release()
{
	Scene::Release();
}

void NomadWagonScene::OnEnter()
{
}

void NomadWagonScene::OnExit()
{
}
