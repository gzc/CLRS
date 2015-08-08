/*************************************************************************
	> File Name: colinear.cpp
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
	> Created Time: Sat Aug  8 12:11:59 2015
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int num = 3;

class Point
{
public:
    float x;
    float y;
    Point(float _x, float _y):x(_x),y(_y){}
    Point():x(0.0),y(0.0){}
    
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
    
    void reverse()
    {
        this->x = -x;
        this->y = -y;
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

float crossProduct(const Point &p1, const Point &p2)
{
    return p1.x*p2.y - p2.x*p1.y;
}

int main() {
    Point p1(0,0);
    Point p2(-1,-1);
    Point p3(2,2);
    
    Point points[num] = {p1,p2,p3};
    Point pointsback[num];
    copy (points, points+num, pointsback);
    
    for(int i = 0;i < num;i++)
    {
        copy(pointsback, pointsback+num, points);
        bool flag[num] = {false};
        for(int j = i+1;j < num;j++)
        {
            points[j] = points[j] - points[i];
            if (points[j].y < 0)
            {
                flag[j] = true;
                points[j].reverse();
            }
        }
        
        sort(points+i+1, points+num, myfunc);
        
        for(int j = i+1; j < num-1;j++)
        {
            if (abs(crossProduct(points[j],points[j+1])) <= 1e-8)
            {
                cout << points[i];
                if (flag[j])
                {
                    flag[j] = false;
                    points[j].reverse();
                }
                cout << points[j];
                if (flag[j+1])
                {
                    flag[j+1] = false;
                    points[j+1].reverse();
                }
                cout << points[j+1];
                cout << "are colinear" << endl;
            }
        }

    }
    
    return 0;
}