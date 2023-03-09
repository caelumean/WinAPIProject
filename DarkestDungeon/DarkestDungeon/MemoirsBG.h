#pragma once
#include "GameObject.h"
#include "Image.h"

class MemoirsBG : public GameObject
{
public:
	MemoirsBG();
	~MemoirsBG();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
};

