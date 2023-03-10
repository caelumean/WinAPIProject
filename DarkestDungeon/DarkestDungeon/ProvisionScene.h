#pragma once
#include "Scene.h"

class ProvisionBG;
class ProvisionScene : public Scene
{
public:
	ProvisionScene();
	~ProvisionScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;

private:
	ProvisionBG* mProvisionBG;
};

