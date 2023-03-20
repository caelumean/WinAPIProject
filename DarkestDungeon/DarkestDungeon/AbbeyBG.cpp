#include "AbbeyBG.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

AbbeyBG::AbbeyBG()
{
}

AbbeyBG::~AbbeyBG()
{
}

void AbbeyBG::Initialize()
{
	mImage = Resources::Load<Image>(L"AbbeyBG", L"..\\Resources\\Town\\abbey\\abbey_bg.bmp");
	GameObject::Initialize();
}


void AbbeyBG::Update()
{
	GameObject::Update();
}

void AbbeyBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x -5, pos.y -5, 1605, 905
		, mImage->GetHdc(), 0, 0, 369, 251, RGB(255, 0, 255));
}

void AbbeyBG::Release()
{
	GameObject::Release();
}
