#include "DGInventoryBG.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"

DGInventoryBG::DGInventoryBG()
{
}

DGInventoryBG::~DGInventoryBG()
{
}

void DGInventoryBG::Initialize()
{
	mImage = Resources::Load<Image>(L"DGInventoryp", L"..\\Resources\\Dugeon\\InfoUI\\Inventory.bmp");
	GameObject::Initialize();
}

void DGInventoryBG::Update()
{
	GameObject::Update();
}

void DGInventoryBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 800, pos.y + 650, 600, 250
		, mImage->GetHdc(), 0, 0, 720, 360, RGB(255, 0, 255));
}

void DGInventoryBG::Release()
{
	GameObject::Release();
}
