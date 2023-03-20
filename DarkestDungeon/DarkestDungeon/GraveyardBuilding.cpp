#include "GraveyardBuilding.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"


GraveyardBuilding::GraveyardBuilding()
{
}

GraveyardBuilding::~GraveyardBuilding()
{
}

void GraveyardBuilding::Initialize()
{
	mImage = Resources::Load<Image>(L"GraveyardBuilding", L"..\\Resources\\Town\\building\\town_graveyard_1.bmp");
	GameObject::Initialize();
}

void GraveyardBuilding::Update()
{
	GameObject::Update();
}

void GraveyardBuilding::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 600, pos.y + 480, 250, 100
		, mImage->GetHdc(), 0, 0, 578, 293, RGB(255, 0, 255));
}

void GraveyardBuilding::Release()
{
	GameObject::Release();
}
