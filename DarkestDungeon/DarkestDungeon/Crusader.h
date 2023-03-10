#pragma once
#include "GameObject.h"
#include "Image.h"

class Crusader : public GameObject
{
public:
	Crusader();
	~Crusader();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
	float mTime;
	int mIdx;
};