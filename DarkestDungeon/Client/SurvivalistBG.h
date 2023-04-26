#pragma once
#include "GameObject.h"
#include "Image.h"

class SurvivalistBG : public GameObject
{
public:
	SurvivalistBG();
	~SurvivalistBG();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
};

