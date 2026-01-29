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

            const Vector2& gravityForce() const;

            Vector2& gravityForce();

            float mass() const;


            // setters

            void setGravityForce(const Vector2&);

            void setMass(float);

        private:

            Vector2 m_GravityForce;

            float m_Mass;

    };

}

#endif