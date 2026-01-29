#include<Vector2.hpp>


// CONSTRUCTORS

Vector2::Vector2(): Vector2(0, 0){}

Vector2::Vector2(float value): Vector2(value, value){}

Vector2::Vector2(float x, float y): m_x(x), m_y(y){}


// MOVE OPERATORS

Vector2& Vector2::operator=(const Vector2& other){

    if( this == &other ){
        return *this;
    }

    m_x = other.m_x;
    m_y = other.m_y;

    return *this;
}

Vector2& Vector2::operator=(Vector2&& other){

    m_x = other.m_x;
    m_y = other.m_y;

    return *this;
}



// ARITHMETIC OPERATORS



// operator +

Vector2 Vector2::operator+(const Vector2& other) const {

    return Vector2(m_x + other.m_x, m_y +  other.m_y);

}

Vector2 Vector2::operator+(Vector2&& other) const {

    return Vector2(m_x + other.m_x, m_y +  other.m_y);
    
}

//operator +=

Vector2& Vector2::operator+=(const Vector2& other){

    m_x = m_x + other.m_x;
    m_y = m_y + other.m_y;

    return *this;

}

Vector2& Vector2::operator+=(Vector2&& other){

    m_x = m_x + other.m_x;
    m_y = m_y + other.m_y;

    return *this;

}





// operator -

Vector2 Vector2::operator-(const Vector2& other) const {

    return Vector2(m_x - other.m_x, m_y - other.m_y);

}

Vector2 Vector2::operator-(Vector2&& other) const {

    return Vector2(m_x - other.m_x, m_y - other.m_y);
    
}

// operator -=

Vector2& Vector2::operator-=(const Vector2& other){

    m_x = m_x - other.m_x;
    m_y = m_y - other.m_y;

    return *this;

}

Vector2& Vector2::operator-=(Vector2&& other){

    m_x = m_x - other.m_x;
    m_y = m_y - other.m_y;

    return *this;

}



// operator *

Vector2 Vector2::operator*(float factor) const {

    return Vector2(m_x * factor, m_y * factor);

}

// operator *=

Vector2& Vector2::operator*=(float factor){

    m_x = m_x * factor;
    m_y = m_y * factor;

    return *this;

}


// operator ==

bool Vector2::operator==(const Vector2& other) const{
    return (m_x == other.m_x && m_y == other.m_y);
}
        
bool Vector2::operator==(Vector2&& other) const{
    return (m_x == other.m_x && m_y == other.m_y);
}



// GETTERS

float Vector2::getX() const {
    return m_x;
}

float Vector2::getY() const {
    return m_y;
}