#include "InfoUIBG.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"

InfoUIBG::InfoUIBG()
{
}

InfoUIBG::~InfoUIBG()
{
}

void InfoUIBG::Initialize()
{
	//D:\WinAPIProject\DarkestDungeon\Resources\Dugeon\InfoUI
	mImage[0] = Resources::Load<Image>(L"InfoBG", L"..\\Resources\\Dugeon\\InfoUI\\BlackBackground.bmp");

	mImage[1] = Resources::Load<Image>(L"Side_decor1", L"..\\Resources\\Dugeon\\InfoUI\\side_decor1.bmp");
	mImage[2] = Resources::Load<Image>(L"Side_decor2", L"..\\Resources\\Dugeon\\InfoUI\\side_decor2.bmp");
	
	GameObject::Initialize();
}

void InfoUIBG::Update()
{
	GameObject::Update();
}

void InfoUIBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x - 1, pos.y + 649, 1601, 251
		, mImage[0]->GetHdc(), 0, 0, 811, 731, RGB(255, 0, 255));

	TransparentBlt(hdc, pos.x, pos.y + 650, 200, 250
		, mImage[1]->GetHdc(), 0, 0, 250, 360, RGB(255, 0, 255));
	TransparentBlt(hdc, pos.x + 1400, pos.y + 650, 200, 250
		, mImage[2]->GetHdc(), 0, 0, 250, 360, RGB(255, 0, 255));
}

void InfoUIBG::Release()
{
	GameObject::Release();
}
