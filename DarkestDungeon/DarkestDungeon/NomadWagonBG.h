#pragma once
#include "GameObject.h"
#include "Image.h"

class NomadWagonBG : public GameObject
{
public:
	NomadWagonBG();
	~NomadWagonBG();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
};

