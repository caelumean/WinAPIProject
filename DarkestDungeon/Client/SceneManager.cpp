#include "SceneManager.h"
#include "CollisionManager.h"
#include "Camera.h"

#include "TitleScene.h"
#include "PlayScene.h"

std::vector<Scene*> SceneManager::mScenes = {};
// 현재 씬 초기화
Scene* SceneManager::mActiveScene = nullptr;
void SceneManager::Initialize()
{
	mScenes.resize((UINT)eSceneType::End);

	// eSceneType enum class 안에 있는 Play
	// Play 1번째
	// mScenes[(UINT)eSceneType::Play]->SetName(L"PLAYER");
	// 위와 똑같은 말이다.
	mScenes[(UINT)eSceneType::Title] = new TitleScene();
	mScenes[(UINT)eSceneType::Play] = new PlayScene();

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
