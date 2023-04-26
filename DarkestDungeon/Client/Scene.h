#pragma once
#include "Entity.h"
#include "Layer.h"

class Scene : public Entity
{
public:
	Scene();
	virtual ~Scene();

	virtual void Initialize();
	virtual void Update();
	virtual void Render(HDC hdc);
	virtual void Destroy();
	virtual void Release();

	// 내가 내 씬에 들어왔을 때
	virtual void OnEnter();
	// 내가 내 씬에서 나갔을 때
	virtual void OnExit();

	void AddGameObject(GameObject* obj, eLayerType layer);

	//player에 있는 layer를 다 가져올 것임.
	std::vector<GameObject*>& GetGameObjects(eLayerType layer);

private:
	std::vector<Layer> mLayers;
};

