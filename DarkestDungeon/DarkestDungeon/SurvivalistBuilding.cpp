#include "SurvivalistBuilding.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

SurvivalistBuilding::SurvivalistBuilding()
{
}

SurvivalistBuilding::~SurvivalistBuilding()
{
}

void SurvivalistBuilding::Initialize()
{
	mImage = Resources::Load<Image>(L"SurvivalistBuilding", L"..\\Resources\\Town\\building\\town_survivalist_1.bmp");
	GameObject::Initialize();
}

void SurvivalistBuilding::Update()
{
	GameObject::Update();
}
void SurvivalistBuilding::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 80, pos.y + 380, 160, 140
		, mImage->GetHdc(), 0, 0, 424, 281, RGB(255, 0, 255));
}

void SurvivalistBuilding::Release()
{
	GameObject::Release();
}
