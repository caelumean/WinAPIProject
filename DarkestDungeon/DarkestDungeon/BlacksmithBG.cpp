#include "BlacksmithBG.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

BlacksmithBG::BlacksmithBG()
{
}

BlacksmithBG::~BlacksmithBG()
{
}

void BlacksmithBG::Initialize()
{
	mImage = Resources::Load<Image>(L"BlacksmithBG", L"..\\Resources\\Town\\blacksmith\\blacksmith_bg.bmp");
	GameObject::Initialize();
}

void BlacksmithBG::Update()
{
	GameObject::Update();
}

void BlacksmithBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	BitBlt(hdc, 0, 0, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
}

void BlacksmithBG::Release()
{
	GameObject::Release();
}
