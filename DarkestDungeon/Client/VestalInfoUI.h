#pragma once
#include "GameObject.h"
#include "Image.h"

class VestalInfoUI : public GameObject
{
public:
	VestalInfoUI();
	~VestalInfoUI();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage[7];
};