#include "TavernBG.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

TavernBG::TavernBG()
{
}

TavernBG::~TavernBG()
{
}

void TavernBG::Initialize()
{
	mImage = Resources::Load<Image>(L"TavernBG", L"..\\Resources\\Town\\tavern\\tavern_bg.bmp");
	GameObject::Initialize();
}

void TavernBG::Update()
{
	GameObject::Update();
}

void TavernBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	BitBlt(hdc, 0, 0, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
}

void TavernBG::Release()
{
	GameObject::Release();
}
