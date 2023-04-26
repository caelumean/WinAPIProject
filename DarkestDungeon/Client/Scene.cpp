#include "Scene.h"
#include "SceneManager.h"

Scene::Scene()
{
	//Layer의 용량을 미리 정해둠 (안해도됨)
	mLayers.reserve(5);
	//eLayerType크기 만큼 resize해준다.
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
				// erase함수가 데이터를 지운다음에 다음 iterator를 반환한다.
				// 그래서 다음 iterator를 iter에 받아준다.
				iter = gameObjects.erase(iter);
			}
			else
			{
				iter++;
			}
		}
	}
	// 죽은 위치에서 충돌중인 다른 충돌체가 있었다면 Exit를
	// 호출 해준후에 삭제 해주어야한다.
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
	// layer 타입에 GameObject를 추가해준다.
	mLayers[(UINT)layer].AddGameObject(obj);
}
std::vector<GameObject*>& Scene::GetGameObjects(eLayerType layer)
{
	return mLayers[(UINT)layer].GetGameObjects();
}