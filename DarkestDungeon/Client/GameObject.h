#pragma once
#include "Entity.h"
#include "Component.h"

class GameObject : public Entity
{
public:
	enum class eState
	{
		Active,
		Pause,
		Death,
	};

	GameObject();
	virtual ~GameObject();

	virtual void Initialize();
	virtual void Update();
	virtual void Render(HDC hdc);
	virtual void Release();

	// 충돌을 딱 했을 때 
	virtual void OnCollisionEnter(class Collider* other);
	// 충돌 중일때
	virtual void OnCollisionStay(class Collider* other);
	// 충돌중에서 나갔을때
	virtual void OnCollisionExit(class Collider* other);

	template<typename T>
	T* AddComponent()
	{
		T* comp = new T();
		// component의 GetType함수로 가서 타입을 얻어온다.
		UINT compType = (UINT)comp->GetType();
		mComponents[compType] = comp;
		comp->SetOwner(this);

		return comp;
	}

	// GetComponent해서 상대편의 Collider나 Transform을 이용한
	//무언가를 만들어야 할 때
	template<typename T>
	T* GetComponent()
	{
		for (Component* comp : mComponents)
		{
			if (dynamic_cast<T*>(comp))
				return dynamic_cast<T*>(comp);
		}
		return nullptr;
	}

	// 상태 놓고 얻는거
	eState GetState() { return mState; }
	void SetState(eState state) { mState = state; }
	void SetLayerType(eLayerType type) { mLayerType = type; }
	eLayerType GetLayerType() { return mLayerType; }

private:
	std::vector<Component*> mComponents;
	eState mState;
	eLayerType mLayerType;
};

