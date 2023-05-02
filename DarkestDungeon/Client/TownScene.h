#pragma once
#include "Scene.h"

class TownScene : public Scene
{
public:
	TownScene();
	~TownScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;

private:
	class Sound* Towntheme;

};