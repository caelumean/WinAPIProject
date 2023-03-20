#include "NomadWagonBuilding.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

NomadWagonBuilding::NomadWagonBuilding()
{
}

NomadWagonBuilding::~NomadWagonBuilding()
{
}

void NomadWagonBuilding::Initialize()
{
	mImage = Resources::Load<Image>(L"NomadWagonBuilding", L"..\\Resources\\Town\\building\\town_nomad_wagon_1.bmp");
	GameObject::Initialize();
}

void NomadWagonBuilding::Update()
{
	GameObject::Update();
}

void NomadWagonBuilding::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 780, pos.y + 600, 200, 150
		, mImage->GetHdc(), 0, 0, 514, 392, RGB(255, 0, 255));
}

void NomadWagonBuilding::Release()
{
	GameObject::Release();
}
