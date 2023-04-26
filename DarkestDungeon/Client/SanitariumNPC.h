#pragma once
#include "GameObject.h"
#include "Image.h"

class SanitariumNPC : public GameObject
{
public:
	SanitariumNPC();
	~SanitariumNPC();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
};
