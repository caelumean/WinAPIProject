#pragma once
#include "GameObject.h"
#include "Image.h"

class TownCommonUI2 : public GameObject
{

public:
	TownCommonUI2();
	~TownCommonUI2();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage[2];
};