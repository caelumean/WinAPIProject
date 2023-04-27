#include "TownCommonUI1.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"

TownCommonUI1::TownCommonUI1()
{
}

TownCommonUI1::~TownCommonUI1()
{
}

void TownCommonUI1::Initialize()
{
	mImage[0] = Resources::Load<Image>(L"Namesplate", L"..\\Resources\\Town\\CommonUI_1\\namesplate_2.bmp");
	mImage[1] = Resources::Load<Image>(L"Progressionbar", L"..\\Resources\\Town\\CommonUI_1\\progression_bar.bmp");
	mImage[2] = Resources::Load<Image>(L"Gold", L"..\\Resources\\Town\\CommonUI_1\\gold.bmp");
	mImage[3] = Resources::Load<Image>(L"Bust_Icon", L"..\\Resources\\Town\\CommonUI_1\\bust_icon.bmp");
	mImage[4] = Resources::Load<Image>(L"Portrait_Icon", L"..\\Resources\\Town\\CommonUI_1\\portrait_icon.bmp");
	mImage[5] = Resources::Load<Image>(L"Deed_Icon", L"..\\Resources\\Town\\CommonUI_1\\deed_icon.bmp");
	mImage[6] = Resources::Load<Image>(L"Crest_Icon", L"..\\Resources\\Town\\CommonUI_1\\crest_icon.bmp");
	mImage[7] = Resources::Load<Image>(L"Activity_Log_Button", L"..\\Resources\\Town\\CommonUI_1\\activity_log_button.bmp");
	mImage[8] = Resources::Load<Image>(L"Realm_Inventroy", L"..\\Resources\\Town\\CommonUI_1\\realm_inventory.bmp");
	mImage[9] = Resources::Load<Image>(L"Glossary_Button", L"..\\Resources\\Town\\CommonUI_1\\glossary_button.bmp");
	mImage[10] = Resources::Load<Image>(L"Settings_Button", L"..\\Resources\\Town\\CommonUI_1\\settings_button.bmp");

	GameObject::Initialize();
}

void TownCommonUI1::Update()
{
	GameObject::Update();
}

void TownCommonUI1::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x - 5, pos.y, 700, 250
		, mImage[0]->GetHdc(), 0, 0, 893, 281, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x - 10, pos.y + 780, 1620, 120
		, mImage[1]->GetHdc(), 0, 0, 1920, 138, RGB(255, 0, 255));

	TransparentBlt(hdc, pos.x + 40, pos.y + 780, 90, 90
		, mImage[2]->GetHdc(), 0, 0, 129, 119, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 300, pos.y + 805, 40, 40
		, mImage[3]->GetHdc(), 0, 0, 40, 40, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 375, pos.y + 805, 40, 40
		, mImage[4]->GetHdc(), 0, 0, 40 , 40, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 445, pos.y + 805, 40, 40
		, mImage[5]->GetHdc(), 0, 0, 40, 40, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 515, pos.y + 805, 40, 40
		, mImage[6]->GetHdc(), 0, 0, 40, 40, RGB(255, 0, 255));

	TransparentBlt(hdc, pos.x + 1100, pos.y + 780, 90, 90
		, mImage[7]->GetHdc(), 0, 0, 103, 103, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 1220, pos.y + 780, 90, 90
		, mImage[8]->GetHdc(), 0, 0, 126, 125, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 1320, pos.y + 780, 90, 90
		, mImage[9]->GetHdc(), 0, 0, 102, 112, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 1420, pos.y + 780, 90, 90
		, mImage[10]->GetHdc(), 0, 0, 102, 137, RGB(255, 0, 255));
}

void TownCommonUI1::Release()
{
	GameObject::Release();
}
