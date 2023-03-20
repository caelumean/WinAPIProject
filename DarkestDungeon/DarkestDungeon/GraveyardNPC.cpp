#include "GraveyardNPC.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

GraveyardNPC::GraveyardNPC()
{
}

GraveyardNPC::~GraveyardNPC()
{
}

void GraveyardNPC::Initialize()
{
	//D:\WinAPIProject\DarkestDungeon\Resources\Town\graveyard
	mImage = Resources::Load<Image>(L"GraveyardNPC", L"..\\Resources\\Town\\graveyard\\graveyard_character.bmp");
	GameObject::Initialize();
}

void GraveyardNPC::Update()
{
	GameObject::Update();
}

void GraveyardNPC::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 100, pos.y + 220, 600, 600
		, mImage->GetHdc(), 0, 0, 811, 757, RGB(255, 0, 255));
}

void GraveyardNPC::Release()
{
}
