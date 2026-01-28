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

            inline const Vector2& force() const;

            inline Vector2& force();

            inline const Vector2& speed() const;

            inline Vector2& speed();


            // SETTERS

            inline void setForce(const Vector2&);

            inline void setSpeed(const Vector2&);

        private:

            Vector2 m_Force;

            Vector2 m_Speed;

    };

}

#endif