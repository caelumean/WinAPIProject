#include "Logo.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"

Logo::Logo()
{
}

Logo::~Logo()
{
}

void Logo::Initialize()
{
	mImage = Resources::Load<Image>(L"Logo", L"..\\Resources\\Title\\Logo.bmp");
	GameObject::Initialize();
}

void Logo::Update()
{
	GameObject::Update();
}

void Logo::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 400, pos.y + 50, 800, 300
		, mImage->GetHdc(), 0, 0, 640, 242, RGB(255, 0, 255));
}

void Logo::Release()
{
	GameObject::Release();
}
