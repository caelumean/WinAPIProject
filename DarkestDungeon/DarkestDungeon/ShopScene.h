#pragma once
#include "Scene.h"

class ShopBG;
class ShopScene : public Scene
{
public:
	ShopScene();
	~ShopScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;

private:
	ShopBG* mRuinsBG;
};

