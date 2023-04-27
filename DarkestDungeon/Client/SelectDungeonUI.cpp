#include "SelectDungeonUI.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"

SelectDungeonUI::SelectDungeonUI()
{
}

SelectDungeonUI::~SelectDungeonUI()
{
}

void SelectDungeonUI::Initialize()
{
	mImage[0] = Resources::Load<Image>(L"Ruins", L"..\\Resources\\selDungeon\\Ruins.bmp");
	mImage[1] = Resources::Load<Image>(L"Warren", L"..\\Resources\\selDungeon\\Warren.bmp");
	mImage[2] = Resources::Load<Image>(L"Weald", L"..\\Resources\\selDungeon\\Weald.bmp");
	mImage[3] = Resources::Load<Image>(L"Cove", L"..\\Resources\\selDungeon\\Cove.bmp");
	mImage[4] = Resources::Load<Image>(L"Quest1", L"..\\Resources\\selDungeon\\Quest_select_cleanse.bmp");

	GameObject::Initialize();
}

void SelectDungeonUI::Update()
{
	GameObject::Update();
}

void SelectDungeonUI::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 960, pos.y + 220, 250, 80
		, mImage[0]->GetHdc(), 0, 0, 282, 84, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 790, pos.y + 400, 250, 80
		, mImage[1]->GetHdc(), 0, 0, 282, 84, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 1000, pos.y + 510, 250, 80
		, mImage[2]->GetHdc(), 0, 0, 282, 84, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 1300, pos.y + 400, 250, 80
		, mImage[3]->GetHdc(), 0, 0, 282, 84, RGB(255, 0, 255));

	TransparentBlt(hdc, pos.x + 960, pos.y + 280, 60, 60
		, mImage[4]->GetHdc(), 0, 0, 66, 66, RGB(255, 0, 255));


	
}

void SelectDungeonUI::Release()
{
	GameObject::Release();
}

