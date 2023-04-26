#pragma once
#include "Component.h"


class Transform : public Component
{
public:
	Transform();
	~Transform();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	void SetPos(Vector2 pos) { mPos = pos;}
	void SetScale(Vector2 size) { mScale = size; }
	Vector2 GetPos() { return mPos; }
	Vector2 GetScale() { return mScale; }


private:
	// GameObject가 들고 있던 
	// Pos를 이제 Transform에서 들고있는다.
	Vector2 mPos;
	Vector2 mScale;
};

