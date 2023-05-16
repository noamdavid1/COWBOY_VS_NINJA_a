#include "Point.hpp"

namespace ariel
{
    Point::Point()
    {
    }
    Point::Point(double x, double y)
    {
    }
    bool Point::operator==(const Point &other) const
    {
        return (this->x == other.x && this->y == other.y);
    }
    double Point::distance(Point point)
    {
        return 0.0;
    }
    string Point::print(Point point)
    {
        return "";
    }
    Point Point::moveTowards(Point &point, Point other, double dictace)
    {
        return Point(1.0, 0.0);
    }
}