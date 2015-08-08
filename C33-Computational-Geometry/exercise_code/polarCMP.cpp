/*************************************************************************
	> File Name: polarCMP.cpp
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
    
    friend ostream& operator << (ostream& os, const Point &p)
    {
        os << "x: " << p.x << "  y: " << p.y << endl;
        return os;
    }
};

bool myfunc(const Point &p1, const Point &p2)
{
    if (p1.y > 0 && p2.y < 0) return true;
    else if(p1.y < 0 && p2.y > 0) return false;
    
    if ((p1.x*p2.y - p2.x*p1.y) < 0)
        return false;
    return true;
}

int main() {
    Point p0(1,1);
    Point p1(3,0);
    Point p2(2,2);
    Point p3(0.5,3);
    Point p4(-2,2);
    Point p5(-1,-2);
    
    Point points[5] = {p1,p2,p3,p4,p5};
    for(int i = 0;i < 5;i++)
        points[i] = points[i] - p0;

    sort(points, points+5, myfunc);
    
    for(int i = 0;i < 5;i++)
        cout << (points[i]+p0);

    return 0;
}