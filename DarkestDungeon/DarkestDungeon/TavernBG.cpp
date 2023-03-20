#include "TavernBG.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

TavernBG::TavernBG()
{
}

TavernBG::~TavernBG()
{
}

void TavernBG::Initialize()
{
	mImage = Resources::Load<Image>(L"TavernBG", L"..\\Resources\\Town\\tavern\\tavern_bg.bmp");
	GameObject::Initialize();
}

void TavernBG::Update()
{
	GameObject::Update();
}

void TavernBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	TransparentBlt(hdc, pos.x - 5, pos.y - 5, 1605, 905
		, mImage->GetHdc(), 0, 0, 813, 516, RGB(255, 0, 255));
}

void TavernBG::Release()
{
	GameObject::Release();
}
