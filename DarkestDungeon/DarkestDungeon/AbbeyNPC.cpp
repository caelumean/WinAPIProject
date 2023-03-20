#include "AbbeyNPC.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

AbbeyNPC::AbbeyNPC()
{
}

AbbeyNPC::~AbbeyNPC()
{
}

void AbbeyNPC::Initialize()
{
	//D:\WinAPIProject\DarkestDungeon\Resources\Town\abbey
	mImage = Resources::Load<Image>(L"AbbeyNPC", L"..\\Resources\\Town\\abbey\\abbey_character.bmp");
	GameObject::Initialize();
}

void AbbeyNPC::Update()
{
	GameObject::Update();
}

void AbbeyNPC::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 100, pos.y + 220, 600, 600
		, mImage->GetHdc(), 0, 0, 811, 757, RGB(255, 0, 255));
}

void AbbeyNPC::Release()
{
	GameObject::Release();
}
