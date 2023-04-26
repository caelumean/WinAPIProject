#pragma once
#include "GameObject.h"

class BaseBullet : public GameObject
{
public:
	BaseBullet();
	~BaseBullet();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	float mTime;
};

