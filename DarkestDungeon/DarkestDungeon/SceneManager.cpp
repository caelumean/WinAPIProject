#include "SceneManager.h"
#include "TitleScene.h"

#include "AbbeyScene.h"
#include "BlacksmithScene.h"
#include "GraveyardScene.h"
#include "GuildScene.h"
#include "MemoirsScene.h"
#include "NomadWagonScene.h"
#include "SanitariumScene.h"
#include "StageCoachScene.h"
#include "SurvivalistScene.h"
#include "TavernScene.h"
#include "TownScene.h"

#include "SelectDungeonScene.h"
#include "ProvisionScene.h"
#include "PlayRuinsScene.h"


std::vector<Scene*> SceneManager::mScenes = {};
Scene* SceneManager::mActiveScene = nullptr;

void SceneManager::Initialize()
{
	mScenes.resize((UINT)eSceneType::End);

	// Scene 추가 
	mScenes[(UINT)eSceneType::Title] = new TitleScene();

	// Town 
	mScenes[(UINT)eSceneType::Town] = new TownScene();

	// 타운 건물들 Scene 추가
	mScenes[(UINT)eSceneType::Abbey] = new AbbeyScene();
	mScenes[(UINT)eSceneType::Blacksmith] = new BlacksmithScene();
	mScenes[(UINT)eSceneType::Graveyard] = new GraveyardScene();
	mScenes[(UINT)eSceneType::Guild] = new GuildScene();
	mScenes[(UINT)eSceneType::Memoirs] = new MemoirsScene();
	mScenes[(UINT)eSceneType::NomadWagon] = new NomadWagonScene();
	mScenes[(UINT)eSceneType::Sanitarium] = new SanitariumScene();
	mScenes[(UINT)eSceneType::StageCoach] = new StageCoachScene();
	mScenes[(UINT)eSceneType::Survivalist] = new SurvivalistScene();
	mScenes[(UINT)eSceneType::Tavern] = new TavernScene();

	//던전 관련
	mScenes[(UINT)eSceneType::SelectDugeon] = new SelectDungeonScene();
	mScenes[(UINT)eSceneType::Provision] = new ProvisionScene();
	mScenes[(UINT)eSceneType::Play] = new PlayRuinsScene();

	// 타이틀 씬으로 시작하기
	mActiveScene = mScenes[(UINT)eSceneType::Title];


	for (Scene* scene : mScenes)
	{
		if (scene == nullptr)
			continue;

		scene->Initialize();
	}
}

void SceneManager::Update()
{
	mActiveScene->Update();
}

void SceneManager::Render(HDC hdc)
{
	mActiveScene->Render(hdc);
}

void SceneManager::Release()
{
	for (Scene* scene : mScenes)
	{
		if (scene == nullptr)
			continue;

		delete scene;
		scene = nullptr;
	}
}

void SceneManager::LoadScene(eSceneType type)
{
	// 현재씬
	mActiveScene->OnExit();

	//다음씬
	mActiveScene = mScenes[(UINT)type];
	mActiveScene->OnEnter();
}

