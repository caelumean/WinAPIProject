#pragma once
#include "Scene.h"

class BlacksmithBG;
class BlacksmithScene : public Scene
{
public:
	BlacksmithScene();
	~BlacksmithScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;

private:
	BlacksmithBG* mBlacksmithBG;
};

