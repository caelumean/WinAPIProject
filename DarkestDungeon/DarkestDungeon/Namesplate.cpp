#include "Namesplate.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

Namesplate::Namesplate()
{
}

Namesplate::~Namesplate()
{
}

void Namesplate::Initialize()
{
	mImage = Resources::Load<Image>(L"Namesplate", L"..\\Resources\\Town\\UI\\namesplate.bmp");
	GameObject::Initialize();
}

void Namesplate::Update()
{
	GameObject::Update();
}

void Namesplate::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x - 5, pos.y, 700, 320
		, mImage->GetHdc(), 0, 0, 893, 281, RGB(255, 0, 255));
}

void Namesplate::Release()
{
	GameObject::Release();
}
