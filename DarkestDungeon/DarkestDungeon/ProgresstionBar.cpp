#include "ProgresstionBar.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

ProgresstionBar::ProgresstionBar()
{
}

ProgresstionBar::~ProgresstionBar()
{
}


void ProgresstionBar::Initialize()
{
	mImage = Resources::Load<Image>(L"Progressionbar", L"..\\Resources\\Town\\UI\\progression_bar.bmp");
	GameObject::Initialize();
}

void ProgresstionBar::Update()
{
	GameObject::Update();
}

void ProgresstionBar::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x - 10, pos.y + 780, 1620, 120
		, mImage->GetHdc(), 0, 0, 1920, 138, RGB(255, 0, 255));
}

void ProgresstionBar::Release()
{
	GameObject::Release();
}
