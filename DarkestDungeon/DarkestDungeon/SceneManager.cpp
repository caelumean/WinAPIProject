#include "SceneManager.h"
#include "PlayRuinsScene.h"
#include "StageCoachScene.h"
#include "TownScene.h"
#include "BlacksmithScene.h"
#include "GuildScene.h"
#include "SurvivalistScene.h"
#include "TavernScene.h"
#include "AbbeyScene.h"
#include "SanitariumScene.h"
#include "NomadWagonScene.h"
#include "GraveyardScene.h"
#include "MemoirsScene.h"

#include "TownScene.h"

#include "TitleScene.h"

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
	mScenes[(UINT)eSceneType::StageCoach] = new StageCoachScene();
	mScenes[(UINT)eSceneType::Blacksmith] = new BlacksmithScene();
	mScenes[(UINT)eSceneType::Guild] = new GuildScene();
	mScenes[(UINT)eSceneType::Survivalist] = new SurvivalistScene();
	mScenes[(UINT)eSceneType::Tavern] = new TavernScene();
	mScenes[(UINT)eSceneType::Abbey] = new AbbeyScene();
	mScenes[(UINT)eSceneType::Sanitarium] = new SanitariumScene();
	mScenes[(UINT)eSceneType::NomadWagon] = new NomadWagonScene();
	mScenes[(UINT)eSceneType::Graveyard] = new GraveyardScene();
	mScenes[(UINT)eSceneType::Memoirs] = new MemoirsScene();

	mActiveScene = mScenes[(UINT)eSceneType::Title];
	//mActiveScene = mScenes[(UINT)eSceneType::Town];
	//mActiveScene = mScenes[(UINT)eSceneType::StageCoach];
	//mActiveScene = mScenes[(UINT)eSceneType::Blacksmith];
	//mActiveScene = mScenes[(UINT)eSceneType::Guild];
	//mActiveScene = mScenes[(UINT)eSceneType::Survivalist];
	//mActiveScene = mScenes[(UINT)eSceneType::Tavern];
	//mActiveScene = mScenes[(UINT)eSceneType::Sanitarium];
	//mActiveScene = mScenes[(UINT)eSceneType::NomadWagon];
	//mActiveScene = mScenes[(UINT)eSceneType::Graveyard];
	//mActiveScene = mScenes[(UINT)eSceneType::Memoirs];


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

