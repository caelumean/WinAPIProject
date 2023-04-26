#include "GuildNPCBG.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"

GuildNPCBG::GuildNPCBG()
{
}

GuildNPCBG::~GuildNPCBG()
{
}

void GuildNPCBG::Initialize()
{
	mImage = Resources::Load<Image>(L"GuildNPCBG", L"..\\Resources\\Town\\guild\\guild_character_bg.bmp");
	GameObject::Initialize();
}

void GuildNPCBG::Update()
{
	GameObject::Update();
}

void GuildNPCBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 100, pos.y + 120, 1200, 650
		, mImage->GetHdc(), 0, 0, 1395, 776, RGB(255, 0, 255));
}

void GuildNPCBG::Release()
{
	GameObject::Release();
}
