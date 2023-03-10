#include "TitleBG.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

TitleBG::TitleBG()
{
}

TitleBG::~TitleBG()
{
}

void TitleBG::Initialize()
{
	mImage = Resources::Load<Image>(L"TitleBG", L"..\\Resources\\Title\\title_bg.bmp");
	GameObject::Initialize();
}

void TitleBG::Update()
{
	GameObject::Update();
}

void TitleBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	//BitBlt(hdc, 0, 0, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
	TransparentBlt(hdc, pos.x, pos.y, 1600, 800
		, mImage->GetHdc(), 0, 0, 1920, 2160, RGB(255, 0, 255));
}

void TitleBG::Release()
{
	GameObject::Release();
}
