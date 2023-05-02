#pragma once
#include "GameObject.h"
#include "Image.h"

class CrusaderSword : public GameObject
{
public:
	CrusaderSword();
	~CrusaderSword();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
};
