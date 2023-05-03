#include "CrusaderBattleInfoUI.h"
#include "Crusader.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"
#include "Time.h"
#include "Object.h"

CrusaderBattleInfoUI::CrusaderBattleInfoUI()
	:mTime(0.0f)
{
}

CrusaderBattleInfoUI::~CrusaderBattleInfoUI()
{
}

void CrusaderBattleInfoUI::Initialize()
{
	// 아머 무기 
	mImage[0] = Resources::Load<Image>(L"Crusader_Weapon_01", L"..\\Resources\\Icons_equip_Crusader\\weapon_0.bmp");
	mImage[1] = Resources::Load<Image>(L"Crusader_Armour_01", L"..\\Resources\\Icons_equip_Crusader\\armour_0.bmp");
	// 스킬
	mImage[2] = Resources::Load<Image>(L"Crusader_Ability_11", L"..\\Resources\\Icons_skill_Crusader\\ability_1.bmp");
	mImage[3] = Resources::Load<Image>(L"Crusader_Ability_21", L"..\\Resources\\Icons_skill_Crusader\\ability_3.bmp");
	mImage[4] = Resources::Load<Image>(L"Crusader_Ability_31", L"..\\Resources\\Icons_skill_Crusader\\ability_5.bmp");
	mImage[5] = Resources::Load<Image>(L"Crusader_Ability_41", L"..\\Resources\\Icons_skill_Crusader\\ability_7.bmp");
	// UI이미지 
	mImage[6] = Resources::Load<Image>(L"Crusader_Portrait_1", L"..\\Resources\\Heroes\\crusader_portrait.bmp");
	GameObject::Initialize();
}

void CrusaderBattleInfoUI::Update()
{
	GameObject::Update();

	mTime += Time::DeltaTime();

	// 시간이 지나면 삭제
	if (mTime > 2.0f)
	{
		object::Destory(this);
	}
}

void CrusaderBattleInfoUI::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	// 장비
	TransparentBlt(hdc, pos.x + 425, pos.y + 795, 60, 95
		, mImage[0]->GetHdc(), 0, 0, 72, 144, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 498, pos.y + 795, 60, 95
		, mImage[1]->GetHdc(), 0, 0, 72, 144, RGB(255, 0, 255));

	// 스킬
	TransparentBlt(hdc, pos.x + 436, pos.y + 674, 57, 57
		, mImage[2]->GetHdc(), 0, 0, 72, 72, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 498, pos.y + 674, 57, 57
		, mImage[3]->GetHdc(), 0, 0, 72, 72, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 560, pos.y + 674, 57, 57
		, mImage[4]->GetHdc(), 0, 0, 72, 72, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 622, pos.y + 674, 57, 57
		, mImage[5]->GetHdc(), 0, 0, 72, 72, RGB(255, 0, 255));

	//UI이미지
	TransparentBlt(hdc, pos.x + 235, pos.y + 674, 60, 60
		, mImage[6]->GetHdc(), 0, 0, 85, 85, RGB(255, 0, 255));
}

void CrusaderBattleInfoUI::Release()
{
	GameObject::Release();
}
