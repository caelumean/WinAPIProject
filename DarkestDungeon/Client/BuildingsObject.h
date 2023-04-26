#pragma once
#include "GameObject.h"
#include "Image.h"

class BuildingsObject : public GameObject
{
public:
	BuildingsObject();
	~BuildingsObject();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage[10];
};