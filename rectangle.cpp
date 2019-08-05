#include "rectangle.h"
#include <algorithm>

Rectangle::Rectangle() : _width(0), _height(0), _sqr(0)
{
}

Rectangle::Rectangle(int w, int h, bool normal) : _width(w), _height(h), _sqr(w * h),
    _topLeft(0, 0), _topRight(w, 0), _btmLeft(0, h), _btmRight(w, h)
{
    if (normal) {
        /// Ширину записываем не меньшую чем высоту
        auto mnmx = std::minmax(w, h);
        _width = mnmx.second;
        _height = mnmx.first;
    }
}

void Rectangle::updateDimensions()
{
    auto dxdy = _topLeft - _btmRight;
    _width = dxdy.x;
    _height = dxdy.y;
    _sqr = _width * _height;
}

int Rectangle::square() const
{
    return _sqr;
}

Point Rectangle::topLeft() const
{
    return _topLeft;
}

Point Rectangle::topRight() const
{
    return _topRight;
}

Point Rectangle::bottomRight() const
{
    return _btmRight;
}

Point Rectangle::bottomLeft() const
{
    return _btmLeft;
}

void Rectangle::move(Point const& newPos)
{
    _topLeft += newPos;
    _topRight += newPos;
    _btmLeft += newPos;
    _btmRight += newPos;
}

void Rectangle::cutTop(int dx)
{
    _topLeft.y += dx;
    _topRight.y += dx;
    updateDimensions();
}

void Rectangle::cutBottom(int dx)
{
    _btmLeft.y -= dx;
    _btmRight.y -= dx;
    updateDimensions();
}

void Rectangle::cutLeft(int dx)
{
    _topLeft.x += dx;
    _btmLeft.x += dx;
    updateDimensions();
}

void Rectangle::cutRight(int dx)
{
    _topRight.x -= dx;
    _btmRight.x -= dx;
    updateDimensions();
}

Point Rectangle::massCenter()
{
    return (_topLeft + _btmRight) / 2;
}

Rectangle Rectangle::horizontalClone() const
{
    auto mnmx = std::minmax(_width, _height);
    return Rectangle(mnmx.second, mnmx.first);
}

Rectangle Rectangle::verticalClone() const
{
    auto mnmx = std::minmax(_width, _height);
    return Rectangle(mnmx.first, mnmx.second);
}

Rectangle Rectangle::fitWithinClone(const Rectangle &other, bool& horizontal) const
{
    horizontal = other._width > other._height;
    return (horizontal) ? horizontalClone() : verticalClone();
}


bool Rectangle::tryToFitWithin(const Rectangle &other) const
{
    if (other < *this) return false;

    return (normalizedWidth() <= other.normalizedWidth() &&
            normalizedHeight() <= other.normalizedHeight());
}

int Rectangle::width() const
{
    return _width;
}

int Rectangle::height() const
{
    return _height;
}

int Rectangle::normalizedWidth() const
{
    auto mnmx = std::minmax(_width, _height);
    return mnmx.second;
}

int Rectangle::normalizedHeight() const
{
    auto mnmx = std::minmax(_width, _height);
    return mnmx.first;
}


