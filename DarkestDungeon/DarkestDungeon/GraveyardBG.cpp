#include "GraveyardBG.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

GraveyardBG::GraveyardBG()
{
}

GraveyardBG::~GraveyardBG()
{
}

void GraveyardBG::Initialize()
{
	mImage = Resources::Load<Image>(L"GraveyardBG", L"..\\Resources\\Town\\graveyard\\graveyard_bg.bmp");
	GameObject::Initialize();
}

void GraveyardBG::Update()
{
	GameObject::Update();
}

void GraveyardBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	BitBlt(hdc, 0, 0, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
}

void GraveyardBG::Release()
{
	GameObject::Release();
}
