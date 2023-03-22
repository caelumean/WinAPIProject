#include "TavernNPC.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

TavernNPC::TavernNPC()
{
}

TavernNPC::~TavernNPC()
{
}

void TavernNPC::Initialize()
{
	//D:\WinAPIProject\DarkestDungeon\Resources\Town\tavern
	mImage = Resources::Load<Image>(L"TavernNPC", L"..\\Resources\\Town\\tavern\\tavern_character.bmp");
	GameObject::Initialize();
}

void TavernNPC::Update()
{
	GameObject::Update();
	
}

void TavernNPC::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 100, pos.y + 220, 600, 600
		, mImage->GetHdc(), 0, 0, 811, 757, RGB(255, 0, 255));
}

void TavernNPC::Release()
{
	GameObject::Release();
}
