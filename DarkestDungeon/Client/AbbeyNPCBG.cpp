#include "AbbeyNPCBG.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"

AbbeyNPCBG::AbbeyNPCBG()
{
}

AbbeyNPCBG::~AbbeyNPCBG()
{
}

void AbbeyNPCBG::Initialize()
{
	mImage = Resources::Load<Image>(L"AbbeyNPCBG", L"..\\Resources\\Town\\abbey\\abbey_character_bg.bmp");
	GameObject::Initialize();
}

void AbbeyNPCBG::Update()
{
	GameObject::Update();
}

void AbbeyNPCBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 100, pos.y + 120, 1200, 650
		, mImage->GetHdc(), 0, 0, 1395, 776, RGB(255, 0, 255));
}

void AbbeyNPCBG::Release()
{
	GameObject::Release();
}
