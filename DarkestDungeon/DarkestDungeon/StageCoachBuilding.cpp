#include "StageCoachBuilding.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

StageCoachBuilding::StageCoachBuilding()
{
}

StageCoachBuilding::~StageCoachBuilding()
{
}

void StageCoachBuilding::Initialize()
{
	mImage = Resources::Load<Image>(L"StageCoachBuilding", L"..\\Resources\\Town\\building\\town_stage_coach_1.bmp");
	GameObject::Initialize();
}

void StageCoachBuilding::Update()
{
	GameObject::Update();
}

void StageCoachBuilding::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 140, pos.y + 580, 200, 130
		, mImage->GetHdc(), 0, 0, 509, 362, RGB(255, 0, 255));
}

void StageCoachBuilding::Release()
{
	GameObject::Release();
}
