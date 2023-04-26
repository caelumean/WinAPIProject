#include "BlacksmithBG.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"

BlacksmithBG::BlacksmithBG()
{
}

BlacksmithBG::~BlacksmithBG()
{
}

void BlacksmithBG::Initialize()
{
	mImage = Resources::Load<Image>(L"BlacksmithBG", L"..\\Resources\\Town\\blacksmith\\blacksmith_bg.bmp");
	GameObject::Initialize();
}

void BlacksmithBG::Update()
{
	GameObject::Update();
}

void BlacksmithBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x - 5, pos.y - 5, 1605, 905
		, mImage->GetHdc(), 0, 0, 813, 457, RGB(255, 0, 255));
}

void BlacksmithBG::Release()
{
	GameObject::Release();
}
