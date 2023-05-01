#include "VestalInfoUI.h"
#include "Vestal.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"

VestalInfoUI::VestalInfoUI()
{
}

VestalInfoUI::~VestalInfoUI()
{
}

void VestalInfoUI::Initialize()
{
	// �Ƹ� ���� 
	mImage[0] = Resources::Load<Image>(L"Vestal_Weapon_0", L"..\\Resources\\Icons_equip_Vestal\\weapon_0.bmp");
	mImage[1] = Resources::Load<Image>(L"Vestal_Armour_0", L"..\\Resources\\Icons_equip_Vestal\\armour_0.bmp");
	// ��ų
	mImage[2] = Resources::Load<Image>(L"Vestal_Ability_1", L"..\\Resources\\Icons_skill_Vestal\\ability_2.bmp");
	mImage[3] = Resources::Load<Image>(L"Vestal_Ability_2", L"..\\Resources\\Icons_skill_Vestal\\ability_3.bmp");
	mImage[4] = Resources::Load<Image>(L"Vestal_Ability_3", L"..\\Resources\\Icons_skill_Vestal\\ability_5.bmp");
	mImage[5] = Resources::Load<Image>(L"Vestal_Ability_4", L"..\\Resources\\Icons_skill_Vestal\\ability_7.bmp");
	// ũ�缼�̴� UI�̹��� 
	mImage[6] = Resources::Load<Image>(L"Vestal_Portrait", L"..\\Resources\\Heroes\\vestal_portrait_roster.bmp");
	GameObject::Initialize();
}

void VestalInfoUI::Update()
{
	GameObject::Update();
}

void VestalInfoUI::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	// ���
	TransparentBlt(hdc, pos.x + 425, pos.y + 795, 60, 95
		, mImage[0]->GetHdc(), 0, 0, 72, 144, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 498, pos.y + 795, 60, 95
		, mImage[1]->GetHdc(), 0, 0, 72, 144, RGB(255, 0, 255));

	// ��ų
	TransparentBlt(hdc, pos.x + 436, pos.y + 674, 57, 57
		, mImage[2]->GetHdc(), 0, 0, 72, 72, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 498, pos.y + 674, 57, 57
		, mImage[3]->GetHdc(), 0, 0, 72, 72, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 560, pos.y + 674, 57, 57
		, mImage[4]->GetHdc(), 0, 0, 72, 72, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 622, pos.y + 674, 57, 57
		, mImage[5]->GetHdc(), 0, 0, 72, 72, RGB(255, 0, 255));

	//UI�̹���
	TransparentBlt(hdc, pos.x + 235, pos.y + 674, 60, 60
		, mImage[6]->GetHdc(), 0, 0, 85, 85, RGB(255, 0, 255));
}

void VestalInfoUI::Release()
{
	GameObject::Release();
}
