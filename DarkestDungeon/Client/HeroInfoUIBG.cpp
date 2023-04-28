#include "HeroInfoUIBG.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"

HeroInfoUIBG::HeroInfoUIBG()
{
}

HeroInfoUIBG::~HeroInfoUIBG()
{
}

void HeroInfoUIBG::Initialize()
{

	mImage[0] = Resources::Load<Image>(L"Hero_Info_1", L"..\\Resources\\Dugeon\\InfoUI\\hero_Info_1.bmp");
	mImage[1] = Resources::Load<Image>(L"Hero_Info_2", L"..\\Resources\\Dugeon\\InfoUI\\hero_Info_2.bmp");

	GameObject::Initialize();
}

void HeroInfoUIBG::Update()
{
	GameObject::Update();
}

void HeroInfoUIBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 210, pos.y + 650, 580, 100
		, mImage[0]->GetHdc(), 0, 0, 713, 136, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 210, pos.y + 760, 580, 150
		, mImage[1]->GetHdc(), 0, 0, 713, 224, RGB(255, 0, 255));
	
}

void HeroInfoUIBG::Release()
{
	GameObject::Release();
}
