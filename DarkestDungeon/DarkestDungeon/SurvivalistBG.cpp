#include "SurvivalistBG.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

SurvivalistBG::SurvivalistBG()
{
}

SurvivalistBG::~SurvivalistBG()
{
}

void SurvivalistBG::Initialize()
{
	mImage = Resources::Load<Image>(L"SurvivalistBG", L"..\\Resources\\Town\\survivalist\\survivalist_bg.bmp");
	GameObject::Initialize();
}

void SurvivalistBG::Update()
{
	GameObject::Update();
}

void SurvivalistBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	BitBlt(hdc, 0, 0, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
}

void SurvivalistBG::Release()
{
	GameObject::Release();
}
