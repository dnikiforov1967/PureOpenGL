#ifndef TRIANGULAR_H
#define TRIANGULAR_H

#include "point.h"

class Triangular
{
    Point va,vb,vc;
public:
    Triangular() = delete;
    Triangular(Point&, Point&, Point&) noexcept;
};

#endif // TRIANGULAR_H
