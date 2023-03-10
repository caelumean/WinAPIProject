#pragma once
#include "Scene.h"

class TitleBG;
class Logo;
class StartButton;
class TitleHouse;
class TitleScene : public Scene
{
public:
	TitleScene();
	~TitleScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;
private:
	TitleBG* mTitleBG;
	TitleHouse* mTitleHouse;
	Logo* mLogo;
	StartButton* mStartButton;

};