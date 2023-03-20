#pragma once
#include "GameObject.h"
#include "Image.h"

class ProgresstionBar : public GameObject
{
public:
	ProgresstionBar();
	~ProgresstionBar();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
};