#include "TownCommonUI2.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"


TownCommonUI2::TownCommonUI2()
{
}

TownCommonUI2::~TownCommonUI2()
{
}

void TownCommonUI2::Initialize()
{
	mImage[0] = Resources::Load<Image>(L"Abbey_Button", L"..\\Resources\\Town\\CommonUI_2\\abbey_button.bmp");
	mImage[1] = Resources::Load<Image>(L"Blacksmith_Button", L"..\\Resources\\Town\\CommonUI_2\\blacksmith_button.bmp");
	mImage[2] = Resources::Load<Image>(L"Graveyard_Button", L"..\\Resources\\Town\\CommonUI_2\\graveyard_button.bmp");
	mImage[3] = Resources::Load<Image>(L"Guild_Button", L"..\\Resources\\Town\\CommonUI_2\\guild_button.bmp");
	mImage[4] = Resources::Load<Image>(L"Memoirs_Button", L"..\\Resources\\Town\\CommonUI_2\\memoirs_button.bmp");
	mImage[5] = Resources::Load<Image>(L"NomadWagon_Button", L"..\\Resources\\Town\\CommonUI_2\\nomadwagon_button.bmp");
	mImage[6] = Resources::Load<Image>(L"Sanitarium_Button", L"..\\Resources\\Town\\CommonUI_2\\sanitarium_button.bmp");
	mImage[7] = Resources::Load<Image>(L"StageCoach_Button", L"..\\Resources\\Town\\CommonUI_2\\stagecoach_button.bmp");
	mImage[8] = Resources::Load<Image>(L"Survivalist_Button", L"..\\Resources\\Town\\CommonUI_2\\survivalist_button.bmp");
	mImage[9] = Resources::Load<Image>(L"Tavern_button", L"..\\Resources\\Town\\CommonUI_2\\tavern_button.bmp");

	mImage[10] = Resources::Load<Image>(L"Close_Button", L"..\\Resources\\Town\\CommonUI_2\\close_button.bmp");

	GameObject::Initialize();
}

void TownCommonUI2::Update()
{
	GameObject::Update();
}

void TownCommonUI2::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 30, pos.y + 210, 40, 40
		, mImage[0]->GetHdc(), 0, 0, 54, 54, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 30, pos.y + 260, 40, 40
		, mImage[1]->GetHdc(), 0, 0, 54, 54, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 30, pos.y + 310, 40, 40
		, mImage[2]->GetHdc(), 0, 0, 54, 54, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 30, pos.y + 360, 40, 40
		, mImage[3]->GetHdc(), 0, 0, 54, 54, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 30, pos.y + 410, 40, 40
		, mImage[4]->GetHdc(), 0, 0, 54, 54, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 30, pos.y + 460, 40, 40
		, mImage[5]->GetHdc(), 0, 0, 54 , 54, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 30, pos.y + 510, 40, 40
		, mImage[6]->GetHdc(), 0, 0, 54, 54, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 30, pos.y + 560, 40, 40
		, mImage[7]->GetHdc(), 0, 0, 54, 54, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 30, pos.y + 610, 40, 40
		, mImage[8]->GetHdc(), 0, 0, 54, 54, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 30, pos.y + 660, 40, 40
		, mImage[9]->GetHdc(), 0, 0, 54, 54, RGB(255, 0, 255));

	TransparentBlt(hdc, pos.x + 1270, pos.y + 120, 30, 30
		, mImage[10]->GetHdc(), 0, 0, 32, 32, RGB(255, 0, 255));
}

void TownCommonUI2::Release()
{
}
