#include "SanitariumBG.h"
#include "SceneManager.h"
#include "yaResources.h"
#include "Transform.h"

SanitariumBG::SanitariumBG()
{
}

SanitariumBG::~SanitariumBG()
{
}

void SanitariumBG::Initialize()
{
	mImage = Resources::Load<Image>(L"SanitariumBG", L"..\\Resources\\Town\\sanitarium\\sanitarium_bg.bmp");
	GameObject::Initialize();
}

void SanitariumBG::Update()
{
	GameObject::Update();
}

void SanitariumBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	TransparentBlt(hdc, pos.x - 5, pos.y - 5, 1605, 905
		, mImage->GetHdc(), 0, 0, 591, 333, RGB(255, 0, 255));
}

void SanitariumBG::Release()
{
	GameObject::Release();
}
