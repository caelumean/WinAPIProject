#pragma once
#include "GameObject.h"
#include "Image.h"

class TavernBuilding : public GameObject
{
public:
	TavernBuilding();
	~TavernBuilding();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
};
