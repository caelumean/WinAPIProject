#include "RuinsEntranceBG.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"
#include "Camera.h"


RuinsEntranceBG::RuinsEntranceBG()
{
}

RuinsEntranceBG::~RuinsEntranceBG()
{
}

void RuinsEntranceBG::Initialize()
{
	mImage = Resources::Load<Image>(L"RuinseEntranceRoomBG", L"..\\Resources\\Dugeon\\Ruins\\Ruins_entrance_room.bmp");
	tr = AddComponent<Transform>();
	GameObject::Initialize();
}

void RuinsEntranceBG::Update()
{
	GameObject::Update();
}

void RuinsEntranceBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	pos = Camera::CalculatePos(pos);
	pos.x -= mImage->GetWidth()/15;

	BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
}

void RuinsEntranceBG::Release()
{
	GameObject::Release();
}
