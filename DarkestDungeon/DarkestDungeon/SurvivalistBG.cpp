#include "SurvivalistBG.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

SurvivalistBG::SurvivalistBG()
{
}

SurvivalistBG::~SurvivalistBG()
{
}

void SurvivalistBG::Initialize()
{
	mImage = Resources::Load<Image>(L"SurvivalistBG", L"..\\Resources\\Town\\survivalist\\survivalist_bg.bmp");
	GameObject::Initialize();
}

void SurvivalistBG::Update()
{
	GameObject::Update();
}

void SurvivalistBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	TransparentBlt(hdc, pos.x - 5, pos.y - 5, 1605, 905
		, mImage->GetHdc(), 0, 0, 457, 284, RGB(255, 0, 255));
}

void SurvivalistBG::Release()
{
	GameObject::Release();
}
