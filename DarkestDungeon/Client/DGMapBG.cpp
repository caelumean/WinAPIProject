#include "DGMapBG.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"


DGMapBG::DGMapBG()
{
}

DGMapBG::~DGMapBG()
{
}

void DGMapBG::Initialize()
{
	mImage = Resources::Load<Image>(L"DGMap", L"..\\Resources\\Dugeon\\InfoUI\\Map.bmp");
	GameObject::Initialize();
}

void DGMapBG::Update()
{
	GameObject::Update();
}

void DGMapBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 800, pos.y + 650, 600, 250
		, mImage->GetHdc(), 0, 0, 720, 360, RGB(255, 0, 255));
}

void DGMapBG::Release()
{
	GameObject::Release();
}
