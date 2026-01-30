#include<components/Gravity.hpp>

using namespace afp;




Gravity::Gravity(): Gravity(Vector2(0, -9.8f)){}

Gravity::Gravity(const Vector2& gravityForce): m_GravityForce(gravityForce){}


// getters

const Vector2& Gravity::gravityForce() const { return m_GravityForce; }

Vector2& Gravity::gravityForce(){ return m_GravityForce; }


// setters

void Gravity::setGravityForce(const Vector2& gravityForce){ m_GravityForce = gravityForce; }
