#include "Collider.h"
#include "Transform.h"
#include "GameObject.h"
#include "Camera.h"

UINT Collider::ColliderNumber = 0;
Collider::Collider()
	: Component(eComponentType::Collider)
	, mCenter(Vector2::Zero)
	, mPos(Vector2::Zero)
	, mSize(100.0f, 100.0f)
	, mID(ColliderNumber++)
	, mCollisionCount(0)
{
}

Collider::~Collider()
{
}

void Collider::Initialize()
{
	// ó���� ��������� �� �̸��ѹ� ����
	Transform* tr = GetOwner()->GetComponent<Transform>();
	mPos = tr->GetPos() + mCenter;
}

void Collider::Update()
{
	//Tranform�� GetComponent �ؼ� Tranform�� ������
	Transform* tr = GetOwner()->GetComponent<Transform>();
	// ��ġ�� �����ͼ� Center�� ����
	mPos = tr->GetPos() + mCenter;
}

void Collider::Render(HDC hdc)
{
	HPEN pen = NULL;
	if (mCollisionCount <= 0)
		pen = CreatePen(BS_SOLID, 2, RGB(0, 255, 0));
	else
		pen = CreatePen(BS_SOLID, 2, RGB(255, 0, 0));

	HPEN oldPen = (HPEN)SelectObject(hdc, pen);
	// GetStockObject : ������ �ü���� �̹� �ִ� Object�� ������
	// NULL_BRUSH : ���� �귯���� 
	HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH);
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

	//ī�޶� ���� ����ٰ�
	Vector2 pos = Camera::CaluatePos(mPos);
	Rectangle(hdc, pos.x, pos.y, pos.x + mSize.x, pos.y + mSize.y);

	(HPEN)SelectObject(hdc, oldPen);
	(HBRUSH)SelectObject(hdc, oldBrush);
	DeleteObject(pen);

	mCollisionCount = 0;
}

void Collider::Release()
{
}

void Collider::OnCollisionEnter(Collider* other)
{
	GetOwner()->OnCollisionEnter(other);
}

void Collider::OnCollisionStay(Collider* other)
{
	mCollisionCount = 1;
	GetOwner()->OnCollisionStay(other);
}

void Collider::OnCollisionExit(Collider* other)
{
	GetOwner()->OnCollisionExit(other);
}