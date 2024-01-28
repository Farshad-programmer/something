#include "Star.h"

#include <iostream>


Star2D::Star2D(Vec2D center, int radius1, int radius2, int numSpikes) : mCenter(center), mRadius1(radius1), mRadius2(radius2), mNumSpikes(numSpikes)
{
	mLength1 = Vec2D(mCenter.GetX(), mCenter.GetY() - mRadius1);
	mLength2 = Vec2D(mCenter.GetX(), mCenter.GetY() - mRadius2);
	mLength2.Rotate(pi / (mNumSpikes * 2), mCenter);

	SetLines();
}

void Star2D::SetLines()
{
	mStarLines.clear();
	Line2D currentLine;
	for (size_t i = 0; i < mNumSpikes * 2; i++)
	{
		currentLine.SetP0(mLength1);
		currentLine.SetP1(mLength2);
		mStarLines.push_back(currentLine);
		if(i == 0)return;

		if ((i % 2) == 0)
		{
			mLength1.Rotate(pi / mNumSpikes, mCenter);
		}
		else
		{
			mLength2.Rotate(pi / mNumSpikes, mCenter);
		}
	}

}

