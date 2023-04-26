#include "GuildNPC.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"

GuildNPC::GuildNPC()
{
}

GuildNPC::~GuildNPC()
{
}

void GuildNPC::Initialize()
{
	mImage = Resources::Load<Image>(L"GuildNPC", L"..\\Resources\\Town\\guild\\guild_character.bmp");
	GameObject::Initialize();
}

void GuildNPC::Update()
{
	GameObject::Update();
}

void GuildNPC::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 100, pos.y + 220, 600, 600
		, mImage->GetHdc(), 0, 0, 811, 757, RGB(255, 0, 255));
}

void GuildNPC::Release()
{
	GameObject::Release();
}
