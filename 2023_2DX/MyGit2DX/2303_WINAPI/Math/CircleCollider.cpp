#include "framework.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider(float radius, Vector2 center)
: _radius(radius)
, _center(center)
{
	CreatePens();
}

CircleCollider::~CircleCollider()
{
	for(auto pen : _pens)
		DeleteObject(pen);
}

void CircleCollider::Update()
{
}

void CircleCollider::Render(HDC hdc)
{
	SelectObject(hdc, _pens[_curPenIdex]);

	float left = _center.x - _radius;
	float right = _center.x + _radius;
	float top = _center.y - _radius;
	float bottom = _center.y + _radius;

	Ellipse(hdc, left, top, right, bottom);
}

bool CircleCollider::IsCollision(Vector2 pos)
{
	float distance = _center.Distance(pos);

	return distance < _radius;
}

bool CircleCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	float distance = _center.Distance(other->_center);

	return distance < (_radius + other->_radius);
}

bool CircleCollider::IsCollision(shared_ptr<RectCollider> other)
{
	return other->IsCollision(shared_from_this());
}

void CircleCollider::CreatePens()
{
	_curPenIdex = 0;
	_pens.emplace_back(CreatePen(PS_SOLID, 3, GREEN)); // 0
	_pens.emplace_back(CreatePen(PS_SOLID, 3, RED));   // 1
}
