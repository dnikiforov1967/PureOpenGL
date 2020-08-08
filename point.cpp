#include "point.h"

Point::Point(float x, float y, float z) noexcept : cx(x), cy(y), cz(z)
{

}

Point::Point(const Point &p) noexcept
{
    this->cx = p.cx;
    this->cy = p.cy;
    this->cz = p.cz;
}

Point& Point::operator=(const Point &p) noexcept {
    this->cx = p.cx;
    this->cy = p.cy;
    this->cz = p.cz;
    return *this;
}

float Point::getX()
{
    return cx;
}

float Point::getY()
{
    return cy;
}

float Point::getZ()
{
    return cz;
}

