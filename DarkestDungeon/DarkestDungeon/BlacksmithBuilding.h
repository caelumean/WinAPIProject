#pragma once
#include "GameObject.h"
#include "Image.h""

class BlacksmithBuilding : public GameObject
{
public:
	BlacksmithBuilding();
	~BlacksmithBuilding();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
};