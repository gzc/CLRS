/*************************************************************************
	> File Name: convex_polygon.cpp
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

bool isConvexPolygon(Point points[], int n)
{
    bool f1,f2;
    f1 = f2 = false;
    
    for(int i = 0;i < n;i++)
    {
        Point p1 = points[i];
        Point p2 = points[(i+1)%n];
        Point p3 = points[(i+2)%n];
        float d = direction(p2, p1, p3);
        
        if(d > 0 && f2) return false;
        if(d < 0 && f1) return false;
        if(d > 0) f1 = true;
        if(d < 0) f2 = true;
    }
    if(!f1 && !f2) return false;
    
    return true;
}

int main() {
    Point p1(0,0);
    Point p2(1,1);
    Point p3(2,2);
    Point points[3] = {p1,p2,p3};
    bool fff = isConvexPolygon(points, 3);
    
    if(fff) cout << "yes" << endl;
    else cout << "no" << endl;

    return 0;
}