#ifndef _TRANSFORM_
#define _TRANSFORM_

#include "Vector2.hpp"

namespace afp{

    class Transform{

        public:

            Transform();

            Transform(const Vector2&, float, float);

            Transform(const Vector2&);

            Transform(const Transform&) = default;

            Transform(Transform&&) = default;


            // getters

            inline const Vector2& position() const;

            inline Vector2& position();

            inline float scale() const;

            inline float rotationAngle() const;


            // setters

            inline void setPosition(const Vector2&);

            inline void setPosition(Vector2&&);

            inline void setScale(float);

            inline void setRotationAngle(float);



        private:

            Vector2 m_Position;

            float m_Scale;

            float m_RotationAngle;

    };  

}


#endif