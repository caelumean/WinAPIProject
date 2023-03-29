#pragma once
#include "GameObject.h"
#include "Image.h"

class TownCommonUI1 : public GameObject
{
	
public:
	TownCommonUI1();
	~TownCommonUI1();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage[2];
};