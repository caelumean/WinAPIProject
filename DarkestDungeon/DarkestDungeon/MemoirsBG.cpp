#include "MemoirsBG.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

MemoirsBG::MemoirsBG()
{
}

MemoirsBG::~MemoirsBG()
{
}

void MemoirsBG::Initialize()
{
	mImage = Resources::Load<Image>(L"MemoirsBG", L"..\\Resources\\Town\\memoirs\\memoirs_bg.bmp");
	GameObject::Initialize();
}

void MemoirsBG::Update()
{
	GameObject::Update();
}

void MemoirsBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	TransparentBlt(hdc, pos.x - 5, pos.y - 5, 1605, 905
		, mImage->GetHdc(), 0, 0, 747, 460, RGB(255, 0, 255));
}

void MemoirsBG::Release()
{
	GameObject::Release();
}
