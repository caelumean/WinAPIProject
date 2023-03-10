#include "ShopBG.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

ShopBG::ShopBG()
{
}

ShopBG::~ShopBG()
{
}

void ShopBG::Initialize()
{
	mImage = Resources::Load<Image>(L"ShopBG", L"..\\Resources\\Dugeon\\Ruins\\crypts_entrance_room_wall.bmp");
	GameObject::Initialize();
}

void ShopBG::Update()
{
	GameObject::Update();
}

void ShopBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	BitBlt(hdc, 0, 0, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
}

void ShopBG::Release()
{
	GameObject::Release();
}
