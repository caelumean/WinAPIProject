#include "BaseBullet.h"
#include "Transform.h"
#include "Time.h"
#include "Object.h"

BaseBullet::BaseBullet()
	: mTime(0.0f)
{
}

BaseBullet::~BaseBullet()
{
}

void BaseBullet::Initialize()
{
}

void BaseBullet::Update()
{
	Transform* tr = GetComponent<Transform>();

	Vector2 dir = Vector2(500.0f, 500.0f);
	dir.Normalize();

	// -PI를 한 것은 기본적으로 window좌표의 0,0시작점을 생각해보면 된다.
	/*float x = cosf(-PI / 4.0f);
	float y = sinf(-PI / 4.0f);
	45도 만큼 회전시킨 벡터가 요만큼 나온다.
	//float x = dir.x * cosf(PI / 5.0f) - dir.y * sinf(PI / 5.0f);
	//float y = dir.x * sinf(PI / 5.0f) + dir.y * cosf(PI / 5.0f);
	*/

	Vector2 pos = tr->GetPos();
	pos.x += 100.0f * dir.x * Time::DeltaTime();
	pos.y += 100.0f * dir.y * Time::DeltaTime();

	tr->SetPos(pos);

	mTime += Time::DeltaTime();

	// 시간이 지나면 삭제
	if (mTime > 2.0f)
	{
		object::Destory(this);
	}
}

void BaseBullet::Render(HDC hdc)
{
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	HPEN pen = CreatePen(BS_SOLID, 2, RGB(255, 0, 255));

	HPEN oldPen = (HPEN)SelectObject(hdc, pen);
	HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH);
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

	Ellipse(hdc, pos.x, pos.y, pos.x + 50, pos.y + 50);

	(HPEN)SelectObject(hdc, oldPen);
	(HBRUSH)SelectObject(hdc, oldBrush);
	DeleteObject(pen);
}

void BaseBullet::Release()
{
}
