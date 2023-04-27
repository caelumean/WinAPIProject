#include "SelectDungeonBG.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"

SelectDungeonBG::SelectDungeonBG()
{
}

SelectDungeonBG::~SelectDungeonBG()
{
}

void SelectDungeonBG::Initialize()
{
	//D:\WinAPIProject\DarkestDungeon\Resources\selDungeon
	mImage = Resources::Load<Image>(L"SelectDungeonBG", L"..\\Resources\\selDungeon\\select_background.bmp");
	GameObject::Initialize();
}

void SelectDungeonBG::Update()
{
	GameObject::Update();
}

void SelectDungeonBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	BitBlt(hdc, 0, 0, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
}

void SelectDungeonBG::Release()
{
	GameObject::Release();
}
