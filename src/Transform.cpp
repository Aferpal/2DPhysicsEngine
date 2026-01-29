#include<components/Transform.hpp>

using namespace afp;


Transform::Transform(): m_Position(0, 0), m_Scale(1), m_RotationAngle(0){}

Transform::Transform(const Vector2& position, float scale, float rotationAngle): m_Position(position), m_Scale(scale), m_RotationAngle(rotationAngle){}

Transform::Transform(const Vector2& position): Transform(position, 1, 0){}


// getters

const Vector2& Transform::position() const { return m_Position; }

Vector2& Transform::position(){ return m_Position; }

float Transform::scale() const { return m_Scale; }

float Transform::rotationAngle() const { return m_RotationAngle; }


// setters

void Transform::setPosition(const Vector2& position){ m_Position = position; }

void Transform::setPosition(Vector2&& posiiton){ m_Position = posiiton; }

void Transform::setScale(float scale){ m_Scale = scale; }

void Transform::setRotationAngle(float rotationAngle){ m_RotationAngle = rotationAngle; }