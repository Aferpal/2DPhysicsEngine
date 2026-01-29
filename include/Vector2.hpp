#ifndef _VECTOR_2_
#define _VECTOR_2_

class Vector2{
    private:
        float m_x, m_y;
    public:

        // CONSTRUCTORS

        Vector2();
        Vector2(float);
        Vector2(float, float);

        Vector2(const Vector2&) = default;
        Vector2(Vector2&&) = default;


        // MOVE OPERATORS

        Vector2& operator=(const Vector2&);
        Vector2& operator=(Vector2&&);


        // ARITHMETIC OPERATORS

        Vector2 operator+(const Vector2&) const;
        Vector2 operator+(Vector2&&) const;

        Vector2& operator+=(const Vector2&);
        Vector2& operator+=(Vector2&&);

        Vector2 operator-(const Vector2&) const;
        Vector2 operator-(Vector2&&) const;

        Vector2& operator-=(const Vector2&);
        Vector2& operator-=(Vector2&&);

        Vector2 operator*(float) const;
        Vector2& operator*=(float);

        // EQUAL OPERATOR

        bool operator==(const Vector2&) const;
        bool operator==(Vector2&&) const;

        // GETTERS

        float getX() const;

        float getY() const;

};

#endif