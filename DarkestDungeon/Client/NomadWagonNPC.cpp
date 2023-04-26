#include "NomadWagonNPC.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"

NomadWagonNPC::NomadWagonNPC()
{
}

NomadWagonNPC::~NomadWagonNPC()
{
}

void NomadWagonNPC::Initialize()
{
	mImage = Resources::Load<Image>(L"NomadWagonNPC", L"..\\Resources\\Town\\nomadwagon\\nomadwagon_character.bmp");
	GameObject::Initialize();
}

void NomadWagonNPC::Update()
{
	GameObject::Update();
}

void NomadWagonNPC::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 100, pos.y + 220, 600, 600
		, mImage->GetHdc(), 0, 0, 811, 757, RGB(255, 0, 255));
}

void NomadWagonNPC::Release()
{
	GameObject::Release();
}
