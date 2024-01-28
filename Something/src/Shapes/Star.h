#pragma once
#include "../Shapes/Line2D.h"
#include <vector>

class Star2D
{
public:
	Star2D() : Star2D(Vec2D(0, 0), 0, 0, 0) {}
	Star2D(Vec2D center, int radius1, int radius2, int numSpikes);

	inline int GetStarSize() const { return mStarLines.size(); }
	inline Vec2D& GetCenter() { return mCenter; }
	inline Line2D& operator[](size_t index) { return mStarLines[index]; }



private:

	void SetLines();

	Vec2D mCenter;
	Vec2D mLength1;
	Vec2D mLength2;
	std::vector<Line2D> mStarLines;
	int mRadius1;
	int mRadius2;
	int mNumSpikes;

	const float pi = 3.141592 * 2;

};

