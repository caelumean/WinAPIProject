#pragma once
#include "Scene.h"


class SceneManager
{
public:
	static void Initialize();
	static void Update();
	static void Render(HDC hdc);
	static void Destroy();
	static void Release();

	static void LoadScene(eSceneType type);
	static Scene* GetActiveScene() { return mActiveScene; }
	static void SetActiveScene(Scene* scene) { mActiveScene = scene; }

private:
	static std::vector<Scene*> mScenes;

	// 현재의 Scene만 받아오게끔
	static Scene* mActiveScene;
};

