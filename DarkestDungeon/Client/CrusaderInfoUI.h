#pragma once
#include "GameObject.h"
#include "Image.h"

class CrusaderInfoUI : public GameObject
{
public:
	CrusaderInfoUI();
	~CrusaderInfoUI();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage[7];
	float mTime;
};

