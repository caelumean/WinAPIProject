#include "ProvisionNPCBG.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"

ProvisionNPCBG::ProvisionNPCBG()
{
}

ProvisionNPCBG::~ProvisionNPCBG()
{
}

void ProvisionNPCBG::Initialize()
{
	mImage = Resources::Load<Image>(L"ProvisionNPCBG", L"..\\Resources\\selDungeon\\Provision\\provision_NPC_BG.bmp");
	GameObject::Initialize();
}

void ProvisionNPCBG::Update()
{
	GameObject::Update();
}

void ProvisionNPCBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 100, pos.y + 120, 1200, 650
		, mImage->GetHdc(), 0, 0, 1395, 776, RGB(255, 0, 255));
}

void ProvisionNPCBG::Release()
{

}
