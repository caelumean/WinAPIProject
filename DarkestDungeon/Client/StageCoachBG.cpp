#include "StageCoachBG.h"
#include "SceneManager.h"
#include "Resources.h"
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
	TransparentBlt(hdc, pos.x - 5, pos.y - 5, 1605, 905
		, mImage->GetHdc(), 0, 0, 876, 410, RGB(255, 0, 255));
}

void StageCoachBG::Release()
{
	GameObject::Release();
}
