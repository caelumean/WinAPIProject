#pragma once
#include "GameObject.h"
#include "Scene.h"
#include "SceneManager.h"
#include "Transform.h"

namespace object
{
	// Unity�� Instantiate 
	template<typename T>
	static inline T* Instantiate(eLayerType type)
	{
		T* gameObj = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(gameObj, type);
		gameObj->Initialize();
		return gameObj;
	}

	// ��ġ�� �޾Ƽ� ����� �� �� ����
	template<typename T>
	static inline T* Instantiate(Vector2 pos, eLayerType type)
	{
		T* gameObj = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(gameObj, type);
		// ��ġ�� ���� ������ ���ְ� 
		gameObj->GameObject::GetComponent<Transform>()->SetPos(pos);
		// �ݶ��̴� ���� initialize ������Ѵ�.
		gameObj->Initialize();
		return gameObj;
	}

	// Destory
	static void Destory(GameObject* obj)
	{
		obj->SetState(GameObject::eState::Death);
	}
}