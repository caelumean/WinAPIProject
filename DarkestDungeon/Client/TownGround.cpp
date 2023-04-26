#include "TownGround.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"

TownGround::TownGround()
{
}

TownGround::~TownGround()
{
}

void TownGround::Initialize()
{
	mImage = Resources::Load<Image>(L"TownGround", L"..\\Resources\\Town\\town_ground.bmp");
	GameObject::Initialize();
}

void TownGround::Update()
{
	GameObject::Update();
}

void TownGround::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x - 5, pos.y + 280, 1610, 600
		, mImage->GetHdc(), 0, 0, 3844, 1672, RGB(255, 0, 255));
}

void TownGround::Release()
{
	GameObject::Release();
}
