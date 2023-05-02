#pragma once
#include "GameObject.h"
#include "Image.h"

class HeroHpUI_2 : public GameObject
{

public:
	HeroHpUI_2();
	~HeroHpUI_2();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage[4];
};