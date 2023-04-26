#include "SceneManager.h"
#include "CollisionManager.h"
#include "Camera.h"

#include "TitleScene.h"
#include "PlayScene.h"

std::vector<Scene*> SceneManager::mScenes = {};
// ���� �� �ʱ�ȭ
Scene* SceneManager::mActiveScene = nullptr;
void SceneManager::Initialize()
{
	mScenes.resize((UINT)eSceneType::End);

	// eSceneType enum class �ȿ� �ִ� Play
	// Play 1��°
	// mScenes[(UINT)eSceneType::Play]->SetName(L"PLAYER");
	// ���� �Ȱ��� ���̴�.
	mScenes[(UINT)eSceneType::Title] = new TitleScene();
	mScenes[(UINT)eSceneType::Play] = new PlayScene();

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
