#pragma once
#include "Scene.h"

class SanitariumBG;
class SanitariumScene : public Scene
{
public:
	SanitariumScene();
	~SanitariumScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;
private:
	SanitariumBG* mSanitariumBG;
};

