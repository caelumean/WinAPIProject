#pragma once
#include "Scene.h"

class MemoirsBG;
class MemoirsNPCBG;
class MemoirsNPC;
class ProgressionBar;
class Namesplate;
class MemoirsScene : public Scene
{
public:
	MemoirsScene();
	~MemoirsScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;
private:
	//BG
	MemoirsBG* mMemoirsBG;
	MemoirsNPCBG* mMemoirsNPCBG;
	MemoirsNPC* mMemoirsNPC;
	//UI
	ProgressionBar* mProgressionBar;
	Namesplate* mNamesplate;
};

