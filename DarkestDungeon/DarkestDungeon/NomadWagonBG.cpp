#include "NomadWagonBG.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

NomadWagonBG::NomadWagonBG()
{
}

NomadWagonBG::~NomadWagonBG()
{
}

void NomadWagonBG::Initialize()
{
	mImage = Resources::Load<Image>(L"NomadWagonBG", L"..\\Resources\\Town\\nomadwagon\\nomadwagon_bg.bmp");
	GameObject::Initialize();
}
void NomadWagonBG::Update()
{
	GameObject::Update();
}

void NomadWagonBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	BitBlt(hdc, 0, 0, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
}

void NomadWagonBG::Release()
{
	GameObject::Release();
}
