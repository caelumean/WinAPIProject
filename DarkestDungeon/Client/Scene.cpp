#include "Scene.h"
#include "SceneManager.h"

Scene::Scene()
{
	//Layer�� �뷮�� �̸� ���ص� (���ص���)
	mLayers.reserve(5);
	//eLayerTypeũ�� ��ŭ resize���ش�.
	mLayers.resize((UINT)eLayerType::End);
}

Scene::~Scene()
{
}

void Scene::Initialize()
{
	SceneManager::SetActiveScene(this);
}

void Scene::Update()
{
	for (Layer& layer : mLayers)
	{
		layer.Update();
	}
}

void Scene::Render(HDC hdc)
{
	for (Layer& layer : mLayers)
	{
		layer.Render(hdc);
	}
}

void Scene::Destroy()
{
	std::vector<GameObject*> deleteGameObjects = {};
	for (Layer& layer : mLayers)
	{
		std::vector<GameObject*>& gameObjects
			= layer.GetGameObjects();

		for (std::vector<GameObject*>::iterator iter = gameObjects.begin()
			; iter != gameObjects.end(); )
		{
			if ((*iter)->GetState() == GameObject::eState::Death)
			{
				deleteGameObjects.push_back((*iter));
				// erase�Լ��� �����͸� ��������� ���� iterator�� ��ȯ�Ѵ�.
				// �׷��� ���� iterator�� iter�� �޾��ش�.
				iter = gameObjects.erase(iter);
			}
			else
			{
				iter++;
			}
		}
	}
	// ���� ��ġ���� �浹���� �ٸ� �浹ü�� �־��ٸ� Exit��
	// ȣ�� �����Ŀ� ���� ���־���Ѵ�.
	for (GameObject* deathObj : deleteGameObjects)
	{
		delete deathObj;
		deathObj = nullptr;
	}
}

void Scene::Release()
{
	
}

void Scene::OnEnter()
{
}

void Scene::OnExit()
{
}

void Scene::AddGameObject(GameObject* obj, eLayerType layer)
{
	// layer Ÿ�Կ� GameObject�� �߰����ش�.
	mLayers[(UINT)layer].AddGameObject(obj);
}
std::vector<GameObject*>& Scene::GetGameObjects(eLayerType layer)
{
	return mLayers[(UINT)layer].GetGameObjects();
}