#include "SceneManager.h"
#include "CollisionManager.h"
#include "Camera.h"

#include "TitleScene.h"
#include "TownScene.h"

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
#include "SelectDungeonScene.h"
#include "ProvisionScene.h"

#include "RuinsEntranceScene.h"
#include "RuinsPassageScene.h"
#include "RuinsBattleScene.h"

std::vector<Scene*> SceneManager::mScenes = {};
// 현재 씬 초기화
Scene* SceneManager::mActiveScene = nullptr;
void SceneManager::Initialize()
{
	mScenes.resize((UINT)eSceneType::End);

	//Title Scene
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
	mScenes[(UINT)eSceneType::SelectDugeon] = new SelectDungeonScene();
	mScenes[(UINT)eSceneType::Provision] = new ProvisionScene();

	//던전 Scene 추가
	mScenes[(UINT)eSceneType::RuinsEntrance] = new RuinsEntranceScene();
	mScenes[(UINT)eSceneType::RuinsPassage] = new RuinsPassageScene();
	mScenes[(UINT)eSceneType::RuinsBattle] = new RuinsBattleScene();
	

	// for each문
	for (Scene* scene : mScenes)
	{
		// 예외 처리  
		// scene 안에 아무것도 없을 경우
		if (scene == nullptr)
			continue;

		scene->Initialize();
	}
	mActiveScene = mScenes[(UINT)eSceneType::Title];
}

void SceneManager::Update()
{
	mActiveScene->Update();
}

void SceneManager::Render(HDC hdc)
{
	mActiveScene->Render(hdc);
}

void SceneManager::Destroy()
{
	mActiveScene->Destroy();
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
	Camera::Clear();

	// 현재씬
	mActiveScene->OnExit();

	// Scene이 바뀌기 전에 충돌 체크 초기화 해주기
	CollisionManager::Clear();

	// 다음씬
	mActiveScene = mScenes[(UINT)type];
	mActiveScene->OnEnter();
}
