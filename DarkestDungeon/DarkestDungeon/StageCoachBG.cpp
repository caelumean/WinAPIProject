#include "StageCoachBG.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

StageCoachBG::StageCoachBG()
{
}

StageCoachBG::~StageCoachBG()
{
}

void StageCoachBG::Initialize()
{
	mImage = Resources::Load<Image>(L"StageCoachBG", L"..\\Resources\\Town\\stagecoach\\stagecoach_bg.bmp");
	GameObject::Initialize();
}

void StageCoachBG::Update()
{
	GameObject::Update();
}

void StageCoachBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	BitBlt(hdc, 0, 0, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
}

void StageCoachBG::Release()
{
	GameObject::Release();
}
