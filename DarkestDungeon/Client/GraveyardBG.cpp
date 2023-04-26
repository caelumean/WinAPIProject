#include "GraveyardBG.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"

GraveyardBG::GraveyardBG()
{
}

GraveyardBG::~GraveyardBG()
{
}

void GraveyardBG::Initialize()
{
	mImage = Resources::Load<Image>(L"GraveyardBG", L"..\\Resources\\Town\\graveyard\\graveyard_bg.bmp");
	GameObject::Initialize();
}

void GraveyardBG::Update()
{
	GameObject::Update();
}

void GraveyardBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x - 5, pos.y - 5, 1605, 905
		, mImage->GetHdc(), 0, 0, 465, 247, RGB(255, 0, 255));
}

void GraveyardBG::Release()
{
	GameObject::Release();
}
