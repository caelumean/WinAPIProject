#pragma once
#include "GameObject.h"
#include "Image.h"

class MemoirsNPC : public GameObject
{
public:
	MemoirsNPC();
	~MemoirsNPC();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
};
