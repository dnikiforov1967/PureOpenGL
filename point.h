#ifndef POINT_H
#define POINT_H

//Triplet of coordinates
class Point
{
    //Coordinates
    float cx,cy,cz;
public:
    Point() = delete;
    Point(float x, float y, float z) noexcept;
    Point(const Point&) noexcept;
    Point& operator=(const Point &p) noexcept;
    float getX();
    float getY();
    float getZ();
};

#endif // POINT_H
