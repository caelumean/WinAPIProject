#pragma once
#include "GameObject.h"
#include "Image.h"

class GuildBuilding : public GameObject
{
public:
	GuildBuilding();
	~GuildBuilding();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
};

