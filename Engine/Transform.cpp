#include "Transform.h"

void Transform::Rotate(const float th)
{
	angle += th;
	A = cosf(angle) * size.x;	B = -sinf(angle) * size.y;
	C = sinf(angle) * size.x;	D = cosf(angle) * size.y;
}

void Transform::Scale(const Vec2 v)
{
	size.Scale(v.x, v.y);
	A = cosf(angle) * size.x;	B = -sinf(angle) * size.y;
	C = sinf(angle) * size.x;	D = cosf(angle) * size.y;
}

Vec2 Transform::Forward(Vec2 v)
{
	v = v - center;
	Vec2 vp = {
		(A * v.x) + (B * v.y) + translation.x + center.x,
		(C * v.x) + (D * v.y) + translation.y + center.y
	};
	return vp;
}

void Transform::Invert()
{
	angle = -angle;
	size = { 1.0f / size.x,1.0f / size.y };
	A = cosf(angle) * size.x;	B = -sinf(angle) * size.y;
	C = sinf(angle) * size.x;	D = cosf(angle) * size.y;
}
