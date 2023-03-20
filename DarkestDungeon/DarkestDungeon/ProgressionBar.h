#pragma once
#include "GameObject.h"
#include "Image.h"

class ProgressionBar : public GameObject
{
public:
	ProgressionBar();
	~ProgressionBar();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
};