#pragma once
#include "GameObject.h"
#include "Image.h"

class SanitariumBG : public GameObject
{
public:
	SanitariumBG();
	~SanitariumBG();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
};

