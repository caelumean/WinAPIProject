#include "RuinsEntranceBG.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"



RuinsEntranceBG::RuinsEntranceBG()
{
}

RuinsEntranceBG::~RuinsEntranceBG()
{
}

void RuinsEntranceBG::Initialize()
{
	mImage = Resources::Load<Image>(L"RuinseEntranceRoomBG", L"..\\Resources\\Dugeon\\Ruins\\Ruins_entrance_room.bmp");
	GameObject::Initialize();
}

void RuinsEntranceBG::Update()
{
	GameObject::Update();
}

void RuinsEntranceBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x -1, pos.y -1, 1600, 650
		, mImage->GetHdc(), 0, 0, 1920, 720, RGB(255, 0, 255));
}

void RuinsEntranceBG::Release()
{
	GameObject::Release();
}
