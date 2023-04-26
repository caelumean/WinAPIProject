#include "TavernNPCBG.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"

TavernNPCBG::TavernNPCBG()
{
}

TavernNPCBG::~TavernNPCBG()
{
}

void TavernNPCBG::Initialize()
{
	//D:\WinAPIProject\DarkestDungeon\Resources\Town\tavern
	mImage = Resources::Load<Image>(L"TavernNPCBG", L"..\\Resources\\Town\\tavern\\tavern_character_bg.bmp");
	GameObject::Initialize();
}

void TavernNPCBG::Update()
{
	GameObject::Update();
}

void TavernNPCBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 100, pos.y + 120, 1200, 650
		, mImage->GetHdc(), 0, 0, 1395, 776, RGB(255, 0, 255));
}

void TavernNPCBG::Release()
{
	GameObject::Release();
}
