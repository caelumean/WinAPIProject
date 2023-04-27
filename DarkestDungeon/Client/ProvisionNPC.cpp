#include "ProvisionNPC.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"

ProvisionNPC::ProvisionNPC()
{
}

ProvisionNPC::~ProvisionNPC()
{
}

void ProvisionNPC::Initialize()
{
	//D:\WinAPIProject\DarkestDungeon\Resources\selDungeon\Provision
	mImage = Resources::Load<Image>(L"ProvisionNPC", L"..\\Resources\\selDungeon\\Provision\\provision_character.bmp");
	GameObject::Initialize();
}

void ProvisionNPC::Update()
{
	GameObject::Update();
}

void ProvisionNPC::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 100, pos.y + 220, 600, 600
		, mImage->GetHdc(), 0, 0, 811, 757, RGB(255, 0, 255));
}

void ProvisionNPC::Release()
{
	GameObject::Release();
}
