#include "BoneDefenderAttack.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"

BoneDefenderAttack::BoneDefenderAttack()
{
}

BoneDefenderAttack::~BoneDefenderAttack()
{
}

void BoneDefenderAttack::Initialize()
{
	mImage = Resources::Load<Image>(L"BoneDefender_Attack", L"..\\Resources\\Enemys\\Ruins\\BoneDefender\\BoneDefender_attack.bmp");
}

void BoneDefenderAttack::Update()
{
	GameObject::Update();
}

void BoneDefenderAttack::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 620, pos.y + 200, 400, 400
		, mImage->GetHdc(), 0, 0, 800, 986, RGB(255, 0, 255));
}

void BoneDefenderAttack::Release()
{
	GameObject::Release();
}
