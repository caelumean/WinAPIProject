#include "CrusaderInfoUI.h"
#include "Crusader.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"

CrusaderInfoUI::CrusaderInfoUI()
{
}

CrusaderInfoUI::~CrusaderInfoUI()
{
}

void CrusaderInfoUI::Initialize()
{
	// 아머 무기 
	mImage[0] = Resources::Load<Image>(L"Crusader_Armour_0", L"..\\Resources\\Icons_equip_Crusader\\armour_0.bmp");
	mImage[1] = Resources::Load<Image>(L"Crusader_Weapon_0", L"..\\Resources\\Icons_equip_Crusader\\weapon_0.bmp");
	// 스킬
	mImage[2] = Resources::Load<Image>(L"Crusader_Ability_1", L"..\\Resources\\Icons_skill_Crusader\\ability_1.bmp");
	mImage[3] = Resources::Load<Image>(L"Crusader_Ability_2", L"..\\Resources\\Icons_skill_Crusader\\ability_3.bmp");
	mImage[4] = Resources::Load<Image>(L"Crusader_Ability_3", L"..\\Resources\\Icons_skill_Crusader\\ability_5.bmp");
	mImage[5] = Resources::Load<Image>(L"Crusader_Ability_4", L"..\\Resources\\Icons_skill_Crusader\\ability_7.bmp");
	// 크루세이더 UI이미지 
	mImage[6] = Resources::Load<Image>(L"Crusader_Portrait", L"..\\Resources\\Heroes\\crusader_portrait.bmp");
	GameObject::Initialize();

}

void CrusaderInfoUI::Update()
{
	GameObject::Update();
}

void CrusaderInfoUI::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	// 장비
	TransparentBlt(hdc, pos.x + 210, pos.y + 650, 100, 300
		, mImage[0]->GetHdc(), 0, 0, 72, 144, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 210, pos.y + 650, 100, 300
		, mImage[1]->GetHdc(), 0, 0, 72, 144, RGB(255, 0, 255));

	// 스킬

	//크루세이더 UI이미지
}

void CrusaderInfoUI::Release()
{
	GameObject::Release();
}
