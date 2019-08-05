#include "point.h"
#include "rectangle.h"

bool Point::isInside(const Rectangle &r) const
{
    return this->x >= r.topLeft().x && this->x <= r.bottomRight().x &&
           this->y >= r.topLeft().y && this->y <= r.bottomRight().y ;
}
