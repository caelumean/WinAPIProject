#include "BoneDefenderDefend.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"


BoneDefenderDefend::BoneDefenderDefend()
{
}

BoneDefenderDefend::~BoneDefenderDefend()
{
}

void BoneDefenderDefend::Initialize()
{
	mImage = Resources::Load<Image>(L"BoneDefender_Defend", L"..\\Resources\\Enemys\\Ruins\\BoneDefender\\BoneDefender_defend.bmp");
}

void BoneDefenderDefend::Update()
{
	GameObject::Update();
}

void BoneDefenderDefend::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 720, pos.y + 200, 600, 400
		, mImage->GetHdc(), 0, 0, 499, 621, RGB(255, 0, 255));
}

void BoneDefenderDefend::Release()
{
}
