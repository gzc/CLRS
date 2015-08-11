/*************************************************************************
	> File Name: pointpolygon.cpp
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
	> Created Time: Tue Aug 11 18:53:57 2015
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

class Point;
float direction(const Point &, const Point &, const Point &);
bool onSegmant(const Point &, const Point &, const Point &);

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
    
    bool inTheLine(Point p1, Point p2)
    {
        if ( abs(direction(*this, p1, p2)) < 1e-8 && onSegmant(p1, p2, *this))
            return true;
        return false;
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

/*
 1 means in the polygon
 0 means in the boundary
 -1 means out of the polygon
 */
int point_polygon_pos(Point p0, Point polygon[], int n)
{
    int num(0);
    
    for(int i = 0;i < n;i++)
    {
        Point p1 = polygon[i];
        Point p2 = polygon[(i+1)%n];
        
        if (p0.inTheLine(p1, p2))
            return 0;
        
        float rightmost = max(p1.x, p2.x);
        rightmost += 1.0;
        Point end(rightmost, p0.y);
        bool fff = segmentsInterect(p0, end, p1, p2);
        
        if(fff && ( (p1.y < p0.y && p2.y >= p0.y) || (p2.y < p0.y && p1.y >= p0.y)))
            num++;
    }
    
    return num%2 == 1;
}

int main() {
    Point p0(1, 1);
    
    Point p1(0, 0);
    Point p2(2, 0);
    Point p3(2, 2);
    Point p4(0, 2);
    
    Point Square[4] = {p1, p2, p3, p4};
    int cond = point_polygon_pos(p0, Square, 4);
    cout << cond << endl;
    return 0;
}
