#pragma once
#include "Scene.h"

class TitleScene : public Scene
{
public:
	TitleScene();
	~TitleScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	// 내가 씬을 들어갈 때
	virtual void OnEnter() override;
	// 내가 씬을 나갈 때
	virtual void OnExit() override;
private:
	class Sound* Titletheme;
};

