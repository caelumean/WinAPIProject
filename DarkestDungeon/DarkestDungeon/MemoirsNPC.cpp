#include "MemoirsNPC.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

MemoirsNPC::MemoirsNPC()
{
}

MemoirsNPC::~MemoirsNPC()
{
}

void MemoirsNPC::Initialize()
{
	//D:\WinAPIProject\DarkestDungeon\Resources\Town\memoirs
	mImage = Resources::Load<Image>(L"MemoirsNPC", L"..\\Resources\\Town\\memoirs\\memoirs_character.bmp");
	GameObject::Initialize();
}

void MemoirsNPC::Update()
{
	GameObject::Update();
}

void MemoirsNPC::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	TransparentBlt(hdc, pos.x + 100, pos.y + 220, 600, 600
		, mImage->GetHdc(), 0, 0, 811, 757, RGB(255, 0, 255));
}

void MemoirsNPC::Release()
{
	GameObject::Release();
}
