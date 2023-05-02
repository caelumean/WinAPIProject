#include "HeroHpUI_1.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"
#include "Input.h"
#include "Time.h"

HeroHpUI_1::HeroHpUI_1()
{
}

HeroHpUI_1::~HeroHpUI_1()
{
}

void HeroHpUI_1::Initialize()
{
	//D:\WinAPIProject\DarkestDungeon\Resources\Heroes\Health
	mImage[0] = Resources::Load<Image>(L"CrusaderHP_1", L"..\\Resources\\Heroes\\Health\\health_pip_full.bmp");
	mImage[1] = Resources::Load<Image>(L"HighwayManHP_1", L"..\\Resources\\Heroes\\Health\\health_pip_full.bmp");
	mImage[2] = Resources::Load<Image>(L"PlagueDoctorHP_1", L"..\\Resources\\Heroes\\Health\\health_pip_full.bmp");
	mImage[3] = Resources::Load<Image>(L"VistalHP_1", L"..\\Resources\\Heroes\\Health\\health_pip_full.bmp");

}

void HeroHpUI_1::Update()
{
	GameObject::Update();
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	if (Input::GetKey(eKeyCode::A))
		pos.x -= 200.0f * Time::DeltaTime();

	if (Input::GetKey(eKeyCode::D))
		pos.x += 200.0f * Time::DeltaTime();


	tr->SetPos(pos);
}

void HeroHpUI_1::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	//CrusaderHP
	TransparentBlt(hdc, pos.x + 675, pos.y + 615, 90, 10
		, mImage[0]->GetHdc(), 0, 0, 8, 10, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 535, pos.y + 615, 90, 10
		, mImage[1]->GetHdc(), 0, 0, 8, 10, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 385, pos.y + 615, 90, 10
		, mImage[2]->GetHdc(), 0, 0, 8, 10, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 253, pos.y + 615, 90, 10
		, mImage[1]->GetHdc(), 0, 0, 8, 10, RGB(255, 0, 255));
}

void HeroHpUI_1::Release()
{
	GameObject::Release();
}
