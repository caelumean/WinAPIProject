#include "ProvisionBG.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

ProvisionBG::ProvisionBG()
{
}

ProvisionBG::~ProvisionBG()
{
}

void ProvisionBG::Initialize()
{
	mImage = Resources::Load<Image>(L"ProvisionBG", L"..\\Resources\\Dugeon\\Provision\\provision_background.bmp");
	GameObject::Initialize();
}
void ProvisionBG::Update()
{
	GameObject::Update();
}

void ProvisionBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	BitBlt(hdc, 0, 0, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
}

void ProvisionBG::Release()
{
	GameObject::Release();
}
