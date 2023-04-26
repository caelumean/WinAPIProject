#pragma once
#include "GameObject.h"
#include "Image.h"

class GuildNPC : public GameObject
{
public:
	GuildNPC();
	~GuildNPC();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
};