#pragma once
#include "GameObject.h"
#include "Image.h"

class TitleHouse : public GameObject
{
public:
	TitleHouse();
	~TitleHouse();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
};
