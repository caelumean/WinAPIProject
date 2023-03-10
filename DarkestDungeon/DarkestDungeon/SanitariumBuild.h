#pragma once
#include "GameObject.h"
#include "Image.h"

class SanitariumBuild : public GameObject
{
public:
	SanitariumBuild();
	~SanitariumBuild();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
};