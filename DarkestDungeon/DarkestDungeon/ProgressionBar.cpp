#include "ProgressionBar.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

ProgressionBar::ProgressionBar()
{
}

ProgressionBar::~ProgressionBar()
{
}


void ProgressionBar::Initialize()
{
	mImage = Resources::Load<Image>(L"Progressionbar", L"..\\Resources\\Town\\CommonUI\\progression_bar.bmp");
	GameObject::Initialize();
}

void ProgressionBar::Update()
{
	GameObject::Update();
}

void ProgressionBar::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x - 10, pos.y + 780, 1620, 120
		, mImage->GetHdc(), 0, 0, 1920, 138, RGB(255, 0, 255));
}

void ProgressionBar::Release()
{
	GameObject::Release();
}
