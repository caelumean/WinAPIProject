#pragma once
#include "GameObject.h"
#include "Image.h"

class InfoUIBG : public GameObject
{
public:
	InfoUIBG();
	~InfoUIBG();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage[3];
};
