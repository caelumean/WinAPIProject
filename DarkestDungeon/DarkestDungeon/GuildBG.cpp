#include "GuildBG.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

GuildBG::GuildBG()
{
}

GuildBG::~GuildBG()
{
}

void GuildBG::Initialize()
{
	mImage = Resources::Load<Image>(L"GuildBG", L"..\\Resources\\Town\\guild\\guild_bg.bmp");
	GameObject::Initialize();
}

void GuildBG::Update()
{
	GameObject::Update();
}

void GuildBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	TransparentBlt(hdc, pos.x - 5, pos.y - 5, 1605, 905
		, mImage->GetHdc(), 0, 0, 540, 321, RGB(255, 0, 255));
}

void GuildBG::Release()
{
	GameObject::Release();
}
