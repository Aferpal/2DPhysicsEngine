#ifndef _GRAVITY_
#define _GRAVITY_

#include "Vector2.hpp"

namespace afp{

    class Gravity{

        public:

            Gravity();

            Gravity(float);

            Gravity(const Vector2&, float);

            Gravity(const Gravity&) = default;


            // getters

            inline const Vector2& gravityForce() const;

            inline Vector2& gravityForce();

            inline float mass() const;


            // setters

            inline void setGravityForce(const Vector2&);

            inline void setMass(float);

        private:

            Vector2 m_GravityForce;

            float m_Mass;

    };

}

#endif