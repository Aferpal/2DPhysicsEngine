#ifndef _COLLIDER_
#define _COLLIDER_ 

#include "Vector2.hpp"


namespace afp{

    /**
     *  Basic Rectangle-Shaped collider component
     */
    class Collider{

        public:

            Collider() = default;

            Collider(const Vector2& center, const Vector2& halfSize);

            Collider(const Vector2& halfSize);

            Collider(const Collider&) = default;

            //GETTERS

            const Vector2& center() const;

            Vector2& center();

            const Vector2& halfSize() const;

            Vector2& halfSize();

            // SETTERS

            void setCenter(const Vector2&);

            void setHalfSize(const Vector2&);

        private:

            Vector2 m_Center;

            Vector2 m_HalfSize;

    };
}

#endif