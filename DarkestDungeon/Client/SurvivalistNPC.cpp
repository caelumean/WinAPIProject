#include "SurvivalistNPC.h"
#include "SceneManager.h"
#include "Resources.h"
#include "Transform.h"


SurvivalistNPC::SurvivalistNPC()
{
}

SurvivalistNPC::~SurvivalistNPC()
{
}

void SurvivalistNPC::Initialize()
{
	//D:\WinAPIProject\DarkestDungeon\Resources\Town\survivalist
	mImage = Resources::Load<Image>(L"SurvivalistNPC", L"..\\Resources\\Town\\survivalist\\survivalist_character.bmp");
	GameObject::Initialize();
}

void SurvivalistNPC::Update()
{
	GameObject::Update();
}

void SurvivalistNPC::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 100, pos.y + 220, 600, 600
		, mImage->GetHdc(), 0, 0, 811, 757, RGB(255, 0, 255));
}

void SurvivalistNPC::Release()
{
	GameObject::Release();
}
