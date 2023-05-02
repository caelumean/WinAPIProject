#include "HeroHpUI_2.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"
#include "Input.h"
#include "Time.h"

HeroHpUI_2::HeroHpUI_2()
{
}

HeroHpUI_2::~HeroHpUI_2()
{
}

void HeroHpUI_2::Initialize()
{
	mImage[0] = Resources::Load<Image>(L"CrusaderHP_2", L"..\\Resources\\Heroes\\Health\\health_pip_full.bmp");
	mImage[1] = Resources::Load<Image>(L"HighwayManHP_2", L"..\\Resources\\Heroes\\Health\\health_pip_full.bmp");
	mImage[2] = Resources::Load<Image>(L"PlagueDoctorHP_2", L"..\\Resources\\Heroes\\Health\\health_pip_full.bmp");
	mImage[3] = Resources::Load<Image>(L"VistalHP_2", L"..\\Resources\\Heroes\\Health\\health_pip_full.bmp");
}

void HeroHpUI_2::Update()
{
	GameObject::Update();
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	if (Input::GetKey(eKeyCode::A))
		pos.x -= 0.0f * Time::DeltaTime();

	if (Input::GetKey(eKeyCode::D))
		pos.x += 0.0f * Time::DeltaTime();


	tr->SetPos(pos);
}

void HeroHpUI_2::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	//CrusaderHP
	TransparentBlt(hdc, pos.x + 578, pos.y + 615, 90, 10
		, mImage[0]->GetHdc(), 0, 0, 8, 10, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 438, pos.y + 615, 90, 10
		, mImage[1]->GetHdc(), 0, 0, 8, 10, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 290, pos.y + 615, 90, 10
		, mImage[2]->GetHdc(), 0, 0, 8, 10, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 150, pos.y + 615, 90, 10
		, mImage[1]->GetHdc(), 0, 0, 8, 10, RGB(255, 0, 255));
}

void HeroHpUI_2::Release()
{
	GameObject::Release();
}
