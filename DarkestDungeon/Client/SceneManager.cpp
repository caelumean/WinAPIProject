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
// ���� �� �ʱ�ȭ
Scene* SceneManager::mActiveScene = nullptr;
void SceneManager::Initialize()
{
	mScenes.resize((UINT)eSceneType::End);

	//Title Scene
	mScenes[(UINT)eSceneType::Title] = new TitleScene();
	// Town 
	mScenes[(UINT)eSceneType::Town] = new TownScene();

	// Ÿ�� �ǹ��� Scene �߰�
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

	//���� Scene �߰�
	mScenes[(UINT)eSceneType::RuinsEntrance] = new RuinsEntranceScene();
	mScenes[(UINT)eSceneType::RuinsPassage] = new RuinsPassageScene();
	mScenes[(UINT)eSceneType::RuinsBattle] = new RuinsBattleScene();
	

	// for each��
	for (Scene* scene : mScenes)
	{
		// ���� ó��  
		// scene �ȿ� �ƹ��͵� ���� ���
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

	// �����
	mActiveScene->OnExit();

	// Scene�� �ٲ�� ���� �浹 üũ �ʱ�ȭ ���ֱ�
	CollisionManager::Clear();

	// ������
	mActiveScene = mScenes[(UINT)type];
	mActiveScene->OnEnter();
}
