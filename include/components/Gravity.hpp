#ifndef _GRAVITY_
#define _GRAVITY_

#include <Vector2.hpp>

namespace afp{

    class Gravity{

        public:

            Gravity();

            Gravity(const Vector2&);

            Gravity(const Gravity&) = default;


            // getters

            const Vector2& gravityForce() const;

            Vector2& gravityForce();


            // setters

            void setGravityForce(const Vector2&);

        private:

            Vector2 m_GravityForce;

    };

}

#endif