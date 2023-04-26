#pragma once
#include "GameObject.h"
#include "Scene.h"
#include "SceneManager.h"
#include "Transform.h"

namespace object
{
	// Unity의 Instantiate 
	template<typename T>
	static inline T* Instantiate(eLayerType type)
	{
		T* gameObj = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(gameObj, type);
		gameObj->Initialize();
		return gameObj;
	}

	// 위치를 받아서 만드는 것 또 만듬
	template<typename T>
	static inline T* Instantiate(Vector2 pos, eLayerType type)
	{
		T* gameObj = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(gameObj, type);
		// 위치를 먼저 셋팅을 해주고 
		gameObj->GameObject::GetComponent<Transform>()->SetPos(pos);
		// 콜라이더 포스 initialize 해줘야한다.
		gameObj->Initialize();
		return gameObj;
	}

	// Destory
	static void Destory(GameObject* obj)
	{
		obj->SetState(GameObject::eState::Death);
	}
}