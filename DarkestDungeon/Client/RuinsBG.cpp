#include "RuinsBG.h"
#include "SceneManager.h"
#include "Resources.h"
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

	TransparentBlt(hdc, pos.x -1, pos.y -1, 1600, 900
		, mImage->GetHdc(), 0, 0, 800, 986, RGB(255, 0, 255));
}

void RuinsBG::Release()
{
}
