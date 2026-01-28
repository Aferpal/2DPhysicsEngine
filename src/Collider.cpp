#include<Collider.hpp>


using namespace afp;


Collider::Collider(const Vector2& center, const Vector2& halfSize): m_Center(center), m_HalfSize(halfSize){}

Collider::Collider(const Vector2& halfSize): Collider(Vector2(0, 0), halfSize){}


//GETTERS

const Vector2& Collider::center() const { return m_Center; }

Vector2& Collider::center(){ return m_Center; }

const Vector2& Collider::halfSize() const { return m_HalfSize; }

Vector2& Collider::halfSize(){ return m_HalfSize; }

// SETTERS

void Collider::setCenter(const Vector2& center){ m_Center = center; }

void Collider::setHalfSize(const Vector2& halfSize){ m_HalfSize = halfSize; }