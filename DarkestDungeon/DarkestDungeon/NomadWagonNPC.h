#pragma once
#include "GameObject.h"
#include "Image.h"

class NomadWagonNPC : public GameObject
{
public:
	NomadWagonNPC();
	~NomadWagonNPC();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
};
