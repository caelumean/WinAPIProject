#include "TownBG.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"

TownBG::TownBG()
{
}

TownBG::~TownBG()
{
}

void TownBG::Initialize()
{
	mImage = Resources::Load<Image>(L"TownBG", L"..\\Resources\\Town\\town_bg.bmp");
	GameObject::Initialize();
}

void TownBG::Update()
{
	GameObject::Update();
}

void TownBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	BitBlt(hdc, 0, 0, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
}

void TownBG::Release()
{
	GameObject::Release();
}
