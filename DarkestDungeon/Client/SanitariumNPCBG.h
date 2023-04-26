#pragma once
#include "GameObject.h"
#include "Image.h"

class SanitariumNPCBG : public GameObject
{
public:
	SanitariumNPCBG();
	~SanitariumNPCBG();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
};
