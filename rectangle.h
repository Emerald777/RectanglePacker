#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "point.h"

class Rectangle
{
    int _width;
    int _height;

    int _sqr;

    Point _topLeft;
    Point _topRight;
    Point _btmLeft;
    Point _btmRight;

private:
    void updateDimensions();

public:
    Rectangle();
    Rectangle(int w, int h, bool normal = false); /// normal - width >= height
    Rectangle(const Rectangle& other) = default;

    int square() const;
    Point topLeft() const;
    Point topRight() const;
    Point bottomRight() const;
    Point bottomLeft() const;


    void move(const Point &newPos);

    void cutTop(int dx);
    void cutBottom(int dx);
    void cutLeft(int dx);
    void cutRight(int dx);

    Point massCenter();

    Rectangle horizontalClone() const;
    Rectangle verticalClone() const;
    Rectangle fitWithinClone(const Rectangle& other, bool &horizontal) const;

    /// Deep optimization
    void rotateHorizontal();
    void rotateVecrtical();

    bool tryToFitWithin(const Rectangle& other) const;

    int width() const;
    int height() const;

    int normalizedWidth() const;   /// Maximum of dimensions
    int normalizedHeight() const;  /// Minimum of dimensions

    bool operator<(const Rectangle& other) const {
        return this->_sqr < other._sqr;
    }

    bool operator>(const Rectangle& other) const {
        return this->_sqr > other._sqr;
    }

    Rectangle& operator=(const Rectangle& other) = default;
};

#endif // RECTANGLE_H
