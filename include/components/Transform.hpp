#ifndef _TRANSFORM_
#define _TRANSFORM_

#include <Vector2.hpp>

namespace afp{

    class Transform{

        public:

            Transform();

            Transform(const Vector2&, float, float);

            Transform(const Vector2&);

            Transform(const Transform&) = default;

            Transform(Transform&&) = default;


            // getters

            const Vector2& position() const;

            Vector2& position();

            float scale() const;

            float rotationAngle() const;


            // setters

            void setPosition(const Vector2&);

            void setPosition(Vector2&&);

            void setScale(float);

            void setRotationAngle(float);



        private:

            Vector2 m_Position;

            float m_Scale;

            float m_RotationAngle;

    };  

}


#endif