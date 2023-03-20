#include "GraveyardNPCBG.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

GraveyardNPCBG::GraveyardNPCBG()
{
}

GraveyardNPCBG::~GraveyardNPCBG()
{
}

void GraveyardNPCBG::Initialize()
{
	//D:\WinAPIProject\DarkestDungeon\Resources\Town\graveyard
	mImage = Resources::Load<Image>(L"GraveyardNPCBG", L"..\\Resources\\Town\\graveyard\\graveyard_character_bg.bmp");
	GameObject::Initialize();
}

void GraveyardNPCBG::Update()
{
	GameObject::Update();
}

void GraveyardNPCBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 100, pos.y + 120, 1200, 650
		, mImage->GetHdc(), 0, 0, 1395, 776, RGB(255, 0, 255));
}

void GraveyardNPCBG::Release()
{
	GameObject::Release();
}
