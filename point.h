#ifndef POINT_H
#define POINT_H

class Rectangle;

struct Point
{
    int x;
    int y;

    Point(int x0 = 0, int y0 = 0) : x(x0), y(y0) {}
    Point(const Point& other) = default;

    Point operator+(const Point& other) {
        return Point(other.x + this->x, other.y + this->y);
    }

    Point& operator+=(const Point& other) {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }

    Point operator-(const Point& other) {
        return Point(other.x - this->x, other.y - this->y);
    }

    Point operator/(int n) {
        return Point(this->x / n, this->y / n);
    }

    bool operator==(const Point& other) const {
        return (this->x == other.x && this->y == other.y);
    }

    bool isInside(Rectangle const& r) const;
};

#endif // POINT_H
