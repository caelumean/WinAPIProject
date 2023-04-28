#pragma once
#include "GameObject.h"
#include "Image.h"

class HeroInfoUIBG : public GameObject
{
public:
	HeroInfoUIBG();
	~HeroInfoUIBG();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage[2];
};
