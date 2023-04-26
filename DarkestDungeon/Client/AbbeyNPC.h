#pragma once
#include "GameObject.h"
#include "Image.h"

class AbbeyNPC : public GameObject
{
public:
	AbbeyNPC();
	~AbbeyNPC();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
};