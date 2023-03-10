#include "MemoirsBuilding.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

MemoirsBuilding::MemoirsBuilding()
{
}

MemoirsBuilding::~MemoirsBuilding()
{
}

void MemoirsBuilding::Initialize()
{
	mImage = Resources::Load<Image>(L"MemoirsBuilding", L"..\\Resources\\Town\\building\\town_memoirs_1.bmp");
	GameObject::Initialize();
}

void MemoirsBuilding::Update()
{
	GameObject::Update();
}

void MemoirsBuilding::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 660, pos.y + 530, 150, 200
		, mImage->GetHdc(), 0, 0, 449, 498, RGB(255, 0, 255));
}

void MemoirsBuilding::Release()
{
	GameObject::Release();
}
