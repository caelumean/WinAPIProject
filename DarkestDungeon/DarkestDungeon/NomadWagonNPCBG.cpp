#include "NomadWagonNPCBG.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

NomadWagonNPCBG::NomadWagonNPCBG()
{
}

NomadWagonNPCBG::~NomadWagonNPCBG()
{
}

void NomadWagonNPCBG::Initialize()
{
	//D:\WinAPIProject\DarkestDungeon\Resources\Town\nomadwagon
	mImage = Resources::Load<Image>(L"NomadWagonNPCBG", L"..\\Resources\\Town\\nomadwagon\\nomadwagon_character_bg.bmp");
	GameObject::Initialize();
}

void NomadWagonNPCBG::Update()
{
	GameObject::Update();
}

void NomadWagonNPCBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 100, pos.y + 120, 1200, 650
		, mImage->GetHdc(), 0, 0, 1395, 776, RGB(255, 0, 255));
}

void NomadWagonNPCBG::Release()
{
	GameObject::Release();
}
