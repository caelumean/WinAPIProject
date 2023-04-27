#include "TownCommonUI1.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"

TownCommonUI1::TownCommonUI1()
{
}

TownCommonUI1::~TownCommonUI1()
{
}

void TownCommonUI1::Initialize()
{
	mImage[0] = Resources::Load<Image>(L"Namesplate", L"..\\Resources\\Town\\CommonUI_1\\namesplate.bmp");
	mImage[1] = Resources::Load<Image>(L"Progressionbar", L"..\\Resources\\Town\\CommonUI_1\\progression_bar.bmp");
	GameObject::Initialize();
}

void TownCommonUI1::Update()
{
	GameObject::Update();
}

void TownCommonUI1::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x - 5, pos.y, 700, 250
		, mImage[0]->GetHdc(), 0, 0, 893, 281, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x - 10, pos.y + 780, 1620, 120
		, mImage[1]->GetHdc(), 0, 0, 1920, 138, RGB(255, 0, 255));
}

void TownCommonUI1::Release()
{
	GameObject::Release();
}
