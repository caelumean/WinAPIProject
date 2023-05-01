#pragma once
#include "GameObject.h"
#include "Image.h"

class HighwayManInfoUI : public GameObject
{
public:
	HighwayManInfoUI();
	~HighwayManInfoUI();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage[7];
};