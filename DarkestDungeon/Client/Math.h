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
	// 재정의 하는 것을 쓰는게 아니라 원래 기본에 있던거 
	// 그냥 복사된 된 것을 쓰겠다는 것이다.
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

		// 자기가 계산한걸 다시 돌려준다.
		// 이유 : v6 = v1+ v2 + v3
		// v1+v2 값을 계산한 것을 다시 반환해줘야
		// v1+v2 결과 값에다가 또 v3을 계산을 계산해서 
		// v6에 갈 수 있기 때문이다.
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

	// 위에 Vector2 함수와의 차이점을 알아야한다.
	// v4 = v3+=v1 => 수학에서 안되는 것처럼 똑같이
	// 안되게 막아줄려고 void로 막은 것이다.
	// 반환값이 void이면 막을 수 있으니까.
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

	// 내적 외적 순서가 중요하다
	// 내적
	inline static float Dot(Vector2& v1, Vector2& v2)
	{
		return v1.x * v2.x + v1.y * v2.y;
	}
	// 외적
	inline static float Cross(Vector2& v1, Vector2& v2)
	{
		return v1.x * v2.y - v1.y * v2.x;
	}
}

