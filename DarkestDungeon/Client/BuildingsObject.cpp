#include "BuildingsObject.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"

BuildingsObject::BuildingsObject()
{
}

BuildingsObject::~BuildingsObject()
{
}

void BuildingsObject::Initialize()
{
	mImage[0] = Resources::Load<Image>(L"AbbeyBuilding", L"..\\Resources\\Town\\building\\town_abbey_1.bmp");
	mImage[1] = Resources::Load<Image>(L"BlacksmithBuilding", L"..\\Resources\\Town\\building\\town_blacksmith_1.bmp");
	mImage[2] = Resources::Load<Image>(L"GraveyardBuilding", L"..\\Resources\\Town\\building\\town_graveyard_1.bmp");
	mImage[3] = Resources::Load<Image>(L"GuildBuilding", L"..\\Resources\\Town\\building\\town_guild_1.bmp");
	mImage[4] = Resources::Load<Image>(L"MemoirsBuilding", L"..\\Resources\\Town\\building\\town_memoirs_1.bmp");
	mImage[5] = Resources::Load<Image>(L"NomadWagonBuilding", L"..\\Resources\\Town\\building\\town_nomad_wagon_1.bmp");
	mImage[6] = Resources::Load<Image>(L"SanitariumBuilding", L"..\\Resources\\Town\\building\\town_sanitarium_1.bmp");
	mImage[7] = Resources::Load<Image>(L"StageCoachBuilding", L"..\\Resources\\Town\\building\\town_stage_coach_1.bmp");
	mImage[8] = Resources::Load<Image>(L"SurvivalistBuilding", L"..\\Resources\\Town\\building\\town_survivalist_1.bmp");
	mImage[9] = Resources::Load<Image>(L"TavernBuilding", L"..\\Resources\\Town\\building\\town_tavern_1.bmp");

	GameObject::Initialize();
}
void BuildingsObject::Update()
{
	GameObject::Update();
}

void BuildingsObject::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 620, pos.y + 200, 400, 400
		, mImage[0]->GetHdc(), 0, 0, 800, 986, RGB(255, 0, 255));

	TransparentBlt(hdc, pos.x + 1150, pos.y + 450, 280, 300
		, mImage[1]->GetHdc(), 0, 0, 719, 795, RGB(255, 0, 255));

	TransparentBlt(hdc, pos.x + 610, pos.y + 480, 250, 100
		, mImage[2]->GetHdc(), 0, 0, 578, 293, RGB(255, 0, 255));

	TransparentBlt(hdc, pos.x + 960, pos.y + 300, 300, 400
		, mImage[3]->GetHdc(), 0, 0, 707, 697, RGB(255, 0, 255));

	TransparentBlt(hdc, pos.x + 660, pos.y + 530, 150, 200
		, mImage[4]->GetHdc(), 0, 0, 449, 498, RGB(255, 0, 255));

	TransparentBlt(hdc, pos.x + 780, pos.y + 600, 200, 150
		, mImage[5]->GetHdc(), 0, 0, 514, 392, RGB(255, 0, 255));

	TransparentBlt(hdc, pos.x + 430, pos.y + 150, 300, 500
		, mImage[6]->GetHdc(), 0, 0, 764, 963, RGB(255, 0, 255));

	TransparentBlt(hdc, pos.x + 140, pos.y + 580, 200, 130
		, mImage[7]->GetHdc(), 0, 0, 509, 362, RGB(255, 0, 255));

	TransparentBlt(hdc, pos.x + 80, pos.y + 380, 160, 140
		, mImage[8]->GetHdc(), 0, 0, 424, 281, RGB(255, 0, 255));

	TransparentBlt(hdc, pos.x + 260, pos.y + 410, 300, 300
		, mImage[9]->GetHdc(), 0, 0, 824, 814, RGB(255, 0, 255));
}

void BuildingsObject::Release()
{
}
