#include "NomadWagonBG.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"

NomadWagonBG::NomadWagonBG()
{
}

NomadWagonBG::~NomadWagonBG()
{
}

void NomadWagonBG::Initialize()
{
	mImage = Resources::Load<Image>(L"NomadWagonBG", L"..\\Resources\\Town\\nomadwagon\\nomadwagon_bg.bmp");
	GameObject::Initialize();
}

void NomadWagonBG::Update()
{
	GameObject::Update();
}

void NomadWagonBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	TransparentBlt(hdc, pos.x - 5, pos.y - 5, 1605, 905
		, mImage->GetHdc(), 0, 0, 813, 516, RGB(255, 0, 255));
}

void NomadWagonBG::Release()
{
	GameObject::Release();
}
