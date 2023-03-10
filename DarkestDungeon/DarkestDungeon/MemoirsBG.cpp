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
	BitBlt(hdc, 0, 0, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
}

void MemoirsBG::Release()
{
	GameObject::Release();
}
