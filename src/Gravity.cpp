#include<Gravity.hpp>

using namespace afp;




Gravity::Gravity(): Gravity(Vector2(0, -9.8f), 1){}

Gravity::Gravity(float mass): Gravity(Vector2(0, -9.8f), mass){}

Gravity::Gravity(const Vector2& gravityForce, float mass): m_GravityForce(gravityForce), m_Mass(mass){}


// getters

const Vector2& Gravity::gravityForce() const { return m_GravityForce; }

Vector2& Gravity::gravityForce(){ return m_GravityForce; }

float Gravity::mass() const { return m_Mass; }


// setters

void Gravity::setGravityForce(const Vector2& gravityForce){ m_GravityForce = gravityForce; }

void Gravity::setMass(float mass){ m_Mass = mass; }