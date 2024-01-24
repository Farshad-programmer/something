#include "Vec2D.h"
#include <iostream>
#include "Utils.h"
#include <cassert>
#include <cmath>



const Vec2D Vec2D::Zero;

// friend operators
std::ostream& operator<<(std::ostream& consoleOut, const Vec2D& vec)
{
    consoleOut << "X :" << vec.m_x << " , Y :" << vec.m_y << std::endl;
    return consoleOut;
}


Vec2D operator*(float scale, const Vec2D& otherVec2)
{
	return otherVec2 * scale; // this actualy use operator* we already have and just reorder it
}



// in class operators
bool Vec2D::operator==(const Vec2D& otherVec2) const
{
    return IsEqual(m_x, otherVec2.m_x) && IsEqual(m_y, otherVec2.m_y);
}

bool Vec2D::operator!=(const Vec2D& otherVec2) const
{
    return !(*this == otherVec2);
}

Vec2D Vec2D::operator-() const
{
    return Vec2D(-m_x, -m_y);
}

Vec2D Vec2D::operator*(float scale) const
{
    return Vec2D(scale * m_x, scale * m_y);
}

Vec2D Vec2D::operator/(float scale) const
{
    assert(fabsf(scale) > EPSILON);

    return  Vec2D(m_x / scale, m_y / scale);
}

Vec2D& Vec2D::operator*=(float scale) 
{
    *this = *this * scale;
    return *this;
}

Vec2D& Vec2D::operator/=(float scale) 
{
    assert(fabsf(scale) > EPSILON);

    *this = *this / scale;
    return *this;
}

Vec2D Vec2D::operator+(const Vec2D& otherVec) const
{
    return Vec2D(m_x + otherVec.m_x, m_y + otherVec.m_y);
}

Vec2D Vec2D::operator-(const Vec2D& otherVec) const
{
    return Vec2D(m_x - otherVec.m_x, m_y - otherVec.m_y);
}

Vec2D& Vec2D::operator+=(const Vec2D& otherVec)
{
    *this = *this + otherVec;
    return *this;
}

Vec2D& Vec2D::operator-=(const Vec2D& otherVec)
{
    *this = *this - otherVec;
    return *this;
}

float Vec2D::Mag2() const
{
    //return m_x * m_x + m_y * m_y;
    return Dot(*this);
}

float Vec2D::Mag() const
{
    return sqrt(Mag2());
}

Vec2D Vec2D::GetUnitVec() const
{
    float mag = Mag();

    if (mag > EPSILON)
    {
        return *this / mag;
    }
    return Vec2D::Zero;
}

Vec2D& Vec2D::Normalize()
{
    float mag = Mag();

    if (mag > EPSILON)
    {
    	*this /= mag;
    }

    return *this;
}

float Vec2D::Distance(Vec2D& otherVec) const
{
    return (otherVec - *this).Mag();
}

float Vec2D::Dot(const Vec2D& otherVec) const
{
    return m_x * otherVec.m_x + m_y * otherVec.m_y;
}

Vec2D Vec2D::ProjectOnto(const Vec2D& otherVec) const
{
    Vec2D unitOtherVec = otherVec.GetUnitVec();
    float dot = Dot(unitOtherVec); 
    return otherVec * dot;   
}

float Vec2D::AngleBetween(const Vec2D& otherVec) const
{
    return acosf(GetUnitVec().Dot(otherVec.GetUnitVec()));   // GetUnitVec().Dot(otherVec.GetUnitVec()) be ma cos angle ro mide hala age bekhahim khode angle ro begirim bayad inverse cos ono begirim ke acos hast.
}

Vec2D Vec2D::Reflect(const Vec2D& normal) const
{
    //v - 2(v dot n)n       --> 2(v dot n)n  dar vaghe daghighan kari has ke function ProjectOnto anjam mide
    return *this - 2 * ProjectOnto(normal);
}

void Vec2D::Rotate(float angle, const Vec2D& aroundPoint)
{
   
    float cosine = cosf(angle);
    float sine = sinf(angle);

    Vec2D thisVec(m_x, m_y); // make a copy
    thisVec -= aroundPoint;
    float xRot = thisVec.m_x * cosine - thisVec.m_y * sine;
    float yRot = thisVec.m_x * sine + thisVec.m_y * cosine;

    Vec2D rot = Vec2D(xRot, yRot);
    *this = rot + aroundPoint;
}

Vec2D Vec2D::RotationResult(float angle, const Vec2D& aroundPoint) const
{

    float cosine = cosf(angle);
    float sine = sinf(angle);

    Vec2D thisVec(m_x, m_y); // make a copy
    thisVec -= aroundPoint;
    float xRot = thisVec.m_x * cosine - thisVec.m_y * sine;
    float yRot = thisVec.m_x * sine + thisVec.m_y * cosine;

    Vec2D rot = Vec2D(xRot, yRot);
    return rot + aroundPoint;
}


