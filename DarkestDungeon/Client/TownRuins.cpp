#include "TownRuins.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"

TownRuins::TownRuins()
{
}

TownRuins::~TownRuins()
{
}

void TownRuins::Initialize()
{
	mImage = Resources::Load<Image>(L"TownRuins", L"..\\Resources\\Town\\town_ruins.bmp");
	GameObject::Initialize();
}

void TownRuins::Update()
{
	GameObject::Update();
}

void TownRuins::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x - 5, pos.y + 120, 1200, 400
		, mImage->GetHdc(), 0, 0, 1418, 438, RGB(255, 0, 255));
}

void TownRuins::Release()
{
	GameObject::Release();
}
