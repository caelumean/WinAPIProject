#pragma once
#include "GameObject.h"
#include "Image.h"

class RuinsPassageBG : public GameObject
{
public:
	RuinsPassageBG();
	~RuinsPassageBG();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
	Transform* tr;
};
