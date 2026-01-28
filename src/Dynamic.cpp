#include<Dynamic.hpp>

using namespace afp;


Dynamic::Dynamic(const Vector2& force, const Vector2& speed): m_Force(force), m_Speed(speed){}


//GETTERS

const Vector2& Dynamic::force() const { return m_Force; }

Vector2& Dynamic::force(){ return m_Force; }

const Vector2& Dynamic::speed() const { return m_Speed; }

Vector2& Dynamic::speed(){ return m_Speed; }

// SETTERS

void Dynamic::setForce(const Vector2& force){ m_Force = force; }

void Dynamic::setSpeed(const Vector2& speed){ m_Speed = speed; }