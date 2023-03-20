#include "SanitariumBG.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

SanitariumBG::SanitariumBG()
{
}

SanitariumBG::~SanitariumBG()
{
}

void SanitariumBG::Initialize()
{
	mImage = Resources::Load<Image>(L"SanitariumBG", L"..\\Resources\\Town\\sanitarium\\sanitarium_bg.bmp");
	GameObject::Initialize();
}

void SanitariumBG::Update()
{
	GameObject::Update();
}

void SanitariumBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	BitBlt(hdc, 0, 0, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
}

void SanitariumBG::Release()
{
	GameObject::Release();
}
