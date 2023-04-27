#pragma once
#include <math.h>
#define PI 3.141592


struct Vector2
{
	static Vector2 Up;
	static Vector2 Right;

	static Vector2 One;
	static Vector2 Zero;

	float x;
	float y;

	Vector2()
		: x(0.0f)
		, y(0.0f)
	{

	}
	Vector2(float x, float y)
		: x(x)
		, y(y)
	{

	}
	Vector2(int x, int y)
		: x(x)
		, y(y)
	{

	}
	// ������ �ϴ� ���� ���°� �ƴ϶� ���� �⺻�� �ִ��� 
	// �׳� ����� �� ���� ���ڴٴ� ���̴�.
	Vector2(const Vector2&) = default;
	Vector2& operator=(const Vector2&) = default;

	Vector2(Vector2&&) = default;
	Vector2& operator=(Vector2&&) = default;

	Vector2 operator-()
	{
		return Vector2(-x, -y);
	}

	Vector2 operator+(const Vector2& other)
	{
		Vector2 temp;
		temp.x = x + other.x;
		temp.y = y + other.y;

		return temp;
	}

	Vector2 operator-(const Vector2& other)
	{
		Vector2 temp;
		temp.x = x - other.x;
		temp.y = y - other.y;

		// �ڱⰡ ����Ѱ� �ٽ� �����ش�.
		// ���� : v6 = v1+ v2 + v3
		// v1+v2 ���� ����� ���� �ٽ� ��ȯ�����
		// v1+v2 ��� �����ٰ� �� v3�� ����� ����ؼ� 
		// v6�� �� �� �ֱ� �����̴�.
		return temp;
	}
	Vector2 operator*(const Vector2& other)
	{
		Vector2 temp;
		temp.x = x * other.x;
		temp.y = y * other.y;

		return temp;
	}
	Vector2 operator*(const float ratio)
	{
		Vector2 temp;
		temp.x = x * ratio;
		temp.y = y * ratio;

		return temp;
	}

	Vector2 operator/(const float ratio)
	{
		Vector2 temp;
		temp.x = x / ratio;
		temp.y = y / ratio;

		return temp;
	}

	// ���� Vector2 �Լ����� �������� �˾ƾ��Ѵ�.
	// v4 = v3+=v1 => ���п��� �ȵǴ� ��ó�� �Ȱ���
	// �ȵǰ� �����ٷ��� void�� ���� ���̴�.
	// ��ȯ���� void�̸� ���� �� �����ϱ�.
	void operator+=(const Vector2& other)
	{
		x += other.x;
		y += other.y;
	}

	void operator-=(const Vector2& other)
	{
		x -= other.x;
		y -= other.y;
	}
	void operator*=(const Vector2& other)
	{
		x *= other.x;
		y *= other.y;
	}

	void operator*=(const float& value)
	{
		x *= value;
		y *= value;
	}
	bool operator==(const Vector2& other)
	{
		return (x == other.x && y == other.y);
	}
	void operator-=(const float& value)
	{
		x -= value;
		y -= value;
	}

	void Clear()
	{
		x = 0.0f;
		y = 0.0f;
	}

	float Length()
	{
		return sqrtf(x * x + y * y);
	}

	Vector2& Normalize()
	{
		float length = Length();
		x /= length;
		y /= length;

		return *this;
	}
};

namespace math
{
	//float x = dir.x * cosf(PI / 5.0f) - dir.y * sinf(PI / 5.0f);
	//float y = dir.x * sinf(PI / 5.0f) + dir.y * cosf(PI / 5.0f);

	inline static Vector2 Rotate(Vector2 vector, float degree)
	{
		float radian = (degree / 180.0f) * PI;
		vector.Normalize();

		float x = vector.x * cosf(radian) - vector.y * sinf(radian);
		float y = vector.x * sinf(radian) + vector.y * cosf(radian);
		//atan
		//atan();
		return Vector2(x, y);
	}

	// ���� ���� ������ �߿��ϴ�
	// ����
	inline static float Dot(Vector2& v1, Vector2& v2)
	{
		return v1.x * v2.x + v1.y * v2.y;
	}
	// ����
	inline static float Cross(Vector2& v1, Vector2& v2)
	{
		return v1.x * v2.y - v1.y * v2.x;
	}
}
