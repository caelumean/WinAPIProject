#include "PlagueDoctorInfoUI.h"
#include "PlagueDoctor.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"

PlagueDoctorInfoUI::PlagueDoctorInfoUI()
{
}

PlagueDoctorInfoUI::~PlagueDoctorInfoUI()
{
}

void PlagueDoctorInfoUI::Initialize()
{
	// 아머 무기 
	mImage[0] = Resources::Load<Image>(L"PlagueDoctor_Weapon_0", L"..\\Resources\\Icons_equip_Plague_doctor\\weapon_0.bmp");
	mImage[1] = Resources::Load<Image>(L"PlagueDoctor_Armour_0", L"..\\Resources\\Icons_equip_Plague_doctor\\armour_0.bmp");
	// 스킬
	mImage[2] = Resources::Load<Image>(L"PlagueDoctor_Ability_1", L"..\\Resources\\Icons_skill_Plague_doctor\\ability_1.bmp");
	mImage[3] = Resources::Load<Image>(L"PlagueDoctor_Ability_2", L"..\\Resources\\Icons_skill_Plague_doctor\\ability_7.bmp");
	mImage[4] = Resources::Load<Image>(L"PlagueDoctor_Ability_3", L"..\\Resources\\Icons_skill_Plague_doctor\\ability_2.bmp");
	mImage[5] = Resources::Load<Image>(L"PlagueDoctor_Ability_4", L"..\\Resources\\Icons_skill_Plague_doctor\\ability_3.bmp");
	// UI이미지 
	mImage[6] = Resources::Load<Image>(L"PlagueDoctor_Portrait", L"..\\Resources\\Heroes\\plague_doctor_portrait.bmp");
	GameObject::Initialize();
}

void PlagueDoctorInfoUI::Update()
{
	GameObject::Update();
}

void PlagueDoctorInfoUI::Render(HDC hdc)
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

void PlagueDoctorInfoUI::Release()
{
	GameObject::Release();
}
