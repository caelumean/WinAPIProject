#include "GuildBuilding.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

GuildBuilding::GuildBuilding()
{
}

GuildBuilding::~GuildBuilding()
{
	
}

void GuildBuilding::Initialize()
{
	mImage = Resources::Load<Image>(L"GuildBuilding", L"..\\Resources\\Town\\building\\town_guild_1.bmp");
	GameObject::Initialize();
}

void GuildBuilding::Update()
{
	GameObject::Update();
}

void GuildBuilding::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 940, pos.y + 300, 300, 400
		, mImage->GetHdc(), 0, 0, 707, 697, RGB(255, 0, 255));
}

void GuildBuilding::Release()
{
	GameObject::Release();
}
