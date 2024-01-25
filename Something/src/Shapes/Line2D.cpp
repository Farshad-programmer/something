#include "Line2D.h"
#include <cmath>
#include "../Utils/Utils.h"

Line2D::Line2D()
	:Line2D(Vec2D::Zero,Vec2D::Zero) // this is delegate constructor method
{

}

Line2D::Line2D(float x0, float y0, float x1, float y1)
	:Line2D(Vec2D(x0,y0),Vec2D(x1,y1)) // this is delegate constructor method
{

}

Line2D::Line2D(const Vec2D& p0, const Vec2D& p1)
	:m_p0(p0),m_p1(p1)
{

}

float Line2D::Slope() const // shibe khate
{
	float dx = m_p1.GetX() - m_p0.GetX();
	if(fabsf(dx) < EPSILON)
	{
		return 0;
	}

	float dy = m_p1.GetY() - m_p0.GetY();
	return dy / dx;
}

bool Line2D::operator==(const Line2D& line) const
{
	return line.GetP0() == m_p0 && line.GetP1() == m_p1;
}

float Line2D::MinDistanceFrom(const Vec2D& p, bool limitToSegment) const
{
	return p.Distance(ClosestPoint(p,limitToSegment));
}

Vec2D Line2D::ClosestPoint(const Vec2D& p, bool limitToSegment) const 
{
	// Create a vector from point m_p0 to the input point p
	Vec2D p0ToP = p - m_p0;

	// Create a vector from point m_p0 to point m_p1
	Vec2D p0Top1 = m_p1 - m_p0;

	// Calculate the square of the length of the vector from m_p0 to m_p1
	float l2 = p0Top1.Mag2();

	// Calculate the dot product between the vectors
	float dot = p0ToP.Dot(p0Top1);

	// Calculate the parameter t using the formula t = dot / l2
	float t = dot / l2;

	// If limitToSegment is true, ensure that the parameter t is in the range [0, 1]
	if(limitToSegment)
	{
		t = std::fmax(0, std::fmin(1.f, t));
	}

	// Return the calculated point on the line using the parameter t
	return m_p0 + p0Top1 * t;
}

Vec2D Line2D::MinPoint() const
{
	return Vec2D((m_p0.GetX() + m_p1.GetX()) / 2.f, (m_p0.GetY() + m_p1.GetY()) / 2.f);
}


float Line2D::Length() 
{
	return m_p1.Distance(m_p0);
}


