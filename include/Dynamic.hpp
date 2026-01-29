#ifndef _DYNAMIC_
#define _DYNAMIC_

#include "Vector2.hpp"

namespace afp{

    class Dynamic{  

        public:

            Dynamic() = default;

            Dynamic(const Vector2&, const Vector2&);

            Dynamic(const Dynamic&) = default;


            // GETTERS

            const Vector2& force() const;

            Vector2& force();

            const Vector2& speed() const;

            Vector2& speed();


            // SETTERS

            void setForce(const Vector2&);

            void setSpeed(const Vector2&);

        private:

            Vector2 m_Force;

            Vector2 m_Speed;

    };

}

#endif