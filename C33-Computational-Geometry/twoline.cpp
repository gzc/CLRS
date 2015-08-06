/*************************************************************************
	> File Name: twoline.cpp
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
	> Created Time: Thu Aug  6 17:03:30 2015
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

class Point
{
public:
    float x;
    float y;
    Point(float _x, float _y):x(_x),y(_y){}
    
    Point operator +(const Point &that) const
    {
        return Point(x+that.x, y+that.y);
    }
    
    Point operator -(const Point &that) const
    {
        return Point(x-that.x, y-that.y);
    }
    
    Point& operator =(const Point &that)
    {
        if (this == &that)
            return *this;
        x = that.x;
        y = that.y;
        return *this;
    }
};

float crossProduct(const Point &p1, const Point &p2)
{
    return p1.x*p2.y - p2.x*p1.y;
}

float direction(const Point &pi, const Point &pj, const Point &pk)
{
    return crossProduct(pk-pi, pj-pi);
}

bool onSegmant(const Point &pi, const Point &pj, const Point &pk)
{
    if (min(pi.x, pj.x) <= pk.x && max(pi.x, pj.x) >= pk.x && min(pi.y, pj.y) <= pk.y && max(pi.y, pj.y) >= pk.y)
        return true;
    return false;
}

bool segmentsInterect(const Point &p1, const Point &p2, const Point &p3, const Point &p4)
{
    float d1 = direction(p3, p4, p1);
    float d2 = direction(p3, p4, p2);
    float d3 = direction(p1, p2, p3);
    float d4 = direction(p1, p2, p4);
    if ( ((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)) )
        return true;
    else if (abs(d1) < 1e-8 && onSegmant(p3, p4, p1))
        return true;
    else if (abs(d2) < 1e-8 && onSegmant(p3, p4, p2))
        return true;
    else if (abs(d3) < 1e-8 && onSegmant(p1, p2, p3))
        return true;
    else if (abs(d4) < 1e-8 && onSegmant(p1, p2, p4))
        return true;
    return false;
}

int main() {
    Point p1(0,0);
    Point p2(5,0);
    Point p3(2,2);
    Point p4(2,-2);
    cout << segmentsInterect(p1,p2,p3,p4) << endl;
    cout << segmentsInterect(p1,p3,p2,p4) << endl;

    return 0;
}
