#include "RuinsBG.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

RuinsBG::RuinsBG()
{
}

RuinsBG::~RuinsBG()
{
}

void RuinsBG::Initialize()
{
	mImage = Resources::Load<Image>(L"RuinsBG", L"..\\Resources\\Dugeon\\Ruins\\crypts_entrance_room_wall.bmp");
	GameObject::Initialize();
}

void RuinsBG::Update()
{
	GameObject::Update();
}

void RuinsBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	BitBlt(hdc, 0, 0, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
}

void RuinsBG::Release()
{
	GameObject::Release();
}
