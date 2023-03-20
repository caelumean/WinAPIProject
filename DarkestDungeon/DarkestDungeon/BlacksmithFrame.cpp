#include "BlacksmithFrame.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

BlacksmithFrame::BlacksmithFrame()
{
}

BlacksmithFrame::~BlacksmithFrame()
{
}

void BlacksmithFrame::Initialize()
{
	mImage = Resources::Load<Image>(L"BlacksmithFrame", L"..\\Resources\\Town\\blacksmith\\blacksmith_frame.bmp");
	GameObject::Initialize();
}

void BlacksmithFrame::Update()
{
	GameObject::Update();
}

void BlacksmithFrame::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 900, pos.y + 250, 350, 300
		, mImage->GetHdc(), 0, 0, 467, 360, RGB(255, 0, 255));
}

void BlacksmithFrame::Release()
{
	GameObject::Release();
}
