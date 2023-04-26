#pragma once
#include "GameObject.h"
#include "Image.h"

class TownBG : public GameObject
{
public:
	TownBG();
	~TownBG();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
};

