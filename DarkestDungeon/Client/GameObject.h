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

	// �浹�� �� ���� �� 
	virtual void OnCollisionEnter(class Collider* other);
	// �浹 ���϶�
	virtual void OnCollisionStay(class Collider* other);
	// �浹�߿��� ��������
	virtual void OnCollisionExit(class Collider* other);

	template<typename T>
	T* AddComponent()
	{
		T* comp = new T();
		// component�� GetType�Լ��� ���� Ÿ���� ���´�.
		UINT compType = (UINT)comp->GetType();
		mComponents[compType] = comp;
		comp->SetOwner(this);

		return comp;
	}

	// GetComponent�ؼ� ������� Collider�� Transform�� �̿���
	//���𰡸� ������ �� ��
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

	// ���� ���� ��°�
	eState GetState() { return mState; }
	void SetState(eState state) { mState = state; }
	void SetLayerType(eLayerType type) { mLayerType = type; }
	eLayerType GetLayerType() { return mLayerType; }

private:
	std::vector<Component*> mComponents;
	eState mState;
	eLayerType mLayerType;
};

