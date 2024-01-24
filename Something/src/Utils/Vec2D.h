#pragma once
#include <ostream>

class Vec2D
{
public:

    static const Vec2D Zero;

    Vec2D() :Vec2D(0, 0)
    {

    }
    Vec2D(float x, float y)
        :m_x(x), m_y(y)
    {

    }
    friend std::ostream& operator<<(std::ostream& consoleOut, const Vec2D& vec);

   
    

    bool operator==(const Vec2D& otherVec2) const;
    bool operator!=(const Vec2D& otherVec2) const;
    Vec2D operator-() const;
    Vec2D operator*(float scale) const;
    Vec2D operator/(float scale) const;
    Vec2D& operator*=(float scale);
    Vec2D& operator/=(float scale);
    Vec2D operator+(const Vec2D& otherVec) const;
    Vec2D operator-(const Vec2D& otherVec) const;
    Vec2D& operator+=(const Vec2D& otherVec);
    Vec2D& operator-=(const Vec2D& otherVec);
    float Mag2() const; // magnitude (andaze)
    float Mag() const;
    Vec2D GetUnitVec() const;
    Vec2D& Normalize();
    float Distance(Vec2D& otherVec) const;
    float Dot(const Vec2D& otherVec)const;
    Vec2D ProjectOnto(const Vec2D& otherVec)const;
    float AngleBetween(const Vec2D& otherVec) const;
    Vec2D Reflect(const Vec2D& normal) const;
    void Rotate(float angle, const Vec2D& aroundPoint);
    Vec2D RotationResult(float angle, const Vec2D& aroundPoint) const; // this function just give us result and not do any effect on actual our vector

    friend Vec2D operator*(float scale, const Vec2D& otherVec2); // *** why we used friend here ? read in ***

private:
    float m_x, m_y;

public:
    inline float GetX()const { return m_x; }
    inline float GetY()const { return m_y; }
    inline void SetX(float x) { m_x = x; }
    inline void SetY(float y) { m_y = y; }
};



/*

When you have a member function of a class with a similar name but a
different number of arguments, this situation can lead to ambiguity and
conflict in the compiler. To avoid this ambiguity, the keyword "friend" is
commonly used to consider this function as a non-member function, resolving the ambiguity issue.
In this case, you have certainly understood the matter correctly.
Using "friend" here is an appropriate solution to resolve potential ambiguities in name conflicts and function feature conflicts.
 */