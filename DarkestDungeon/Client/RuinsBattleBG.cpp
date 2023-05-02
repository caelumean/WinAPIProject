#include "RuinsBattleBG.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"
//#include "Camera.h"

RuinsBattleBG::RuinsBattleBG()
{
}

RuinsBattleBG::~RuinsBattleBG()
{
}

void RuinsBattleBG::Initialize()
{
	mImage = Resources::Load<Image>(L"RuinsBattleBG", L"..\\Resources\\Dugeon\\Ruins\\Ruins_battle_room.bmp");
	tr = AddComponent<Transform>();
	GameObject::Initialize();
}

void RuinsBattleBG::Update()
{
	GameObject::Update();
}

void RuinsBattleBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	//pos = Camera::CalculatePos(pos);
	//pos.x -= mImage->GetWidth() / 15;

	BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
}

void RuinsBattleBG::Release()
{
	GameObject::Release();
}
