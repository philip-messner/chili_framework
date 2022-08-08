#pragma once
#include "Vec2.h"

template<typename T>
class Rect
{
public:
	Rect() = default;
	Rect(const Vec2<T>& centerPoint, T width, T height)
		:
		top(centerPoint.y + (T)(height/(T)2)),
		bottom(centerPoint.y - (T)(height / (T)2)),
		right(centerPoint.x + (T)(width / (T)2)),
		left(centerPoint.x - (T)(width / (T)2))
	{}
	Rect(T top, T bottom, T right, T left)
		:
		top(top),
		bottom(bottom),
		right(right),
		left(left)
	{}
	Rect(const Vec2<T>& topLeft, const Vec2<T>& bottomRight)
		:
		top(topLeft.y),
		bottom(bottomRight.y),
		right(bottomRight.x),
		left(topLeft.x)
	{}
	bool isOverlappingWith(const Rect<T>& other) const
	{
		return right > other.left && left < other.right
			&& bottom < other.top && top > other.bottom;
	}

	bool isContainedBy(const Rect<T>& other) const
	{
		return left >= other.left && right <= other.right
			&& top <= other.top && bottom >= other.bottom;
	}

	T getWidth() const
	{
		return right - left;
	}

	T getHeight() const
	{
		return top - bottom;
	}

	Vec2<T> getTopLeft()
	{
		return  Vec2<T>(left, top);
	}

	Vec2<T> getBottomLeft() const
	{
		return Vec2<T>(left, bottom);
	}

	Vec2<T> getMidLeft() const
	{
		return Vec2<T>(left, (T)(top + bottom) / (T)2)
	}

	Vec2<T> getTopRight()
	{
		return  Vec2<T>(right, top);
	}

	Vec2<T> getBottomRight() const
	{
		return Vec2<T>(right, bottom);
	}

	Vec2<T> getMidRight() const
	{
		return Vec2<T>(right, (T)(top + bottom) / (T)2)
	}

	Vec2<T> getTopMid()
	{
		return  Vec2<T>((T)(right + left) / (T)2, top);
	}

	Vec2<T> getBottomMid() const
	{
		return Vec2<T>((T)(right + left) / (T)2, bottom);
	}

	Vec2<T> getCenterPoint() const
	{
		return Vec2<T>((T)(right + left) / (T)2, (T)(top + bottom) / (T)2);
	}

	void TranslateBy(const Vec2<T>& offset)
	{
		top += offset.y;
		bottom += offset.y;
		right += offset.x;
		left += offset.y;
	}
	void Scale(float factor)
	{
		const T curWidth = this->getWidth();
		const T curHeight = this->getHeight();
		const Vec2<T> center = this->getCenterPoint();

		T newWidth = curWidth * factor;
		T newHeight = curHeight * factor;

		top = center.y + ((T)newHeight) / (T)2;
		bottom = center.y - ((T)newHeight) / (T)2;
		right = center.x + ((T)newWidth) / (T)2;
		left = center.x + ((T)newWidth) / (T)2;
	}

public:
	T top;
	T bottom;
	T right;
	T left;
};
