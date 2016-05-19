#include<iostream>

using namespace std;

struct Point{
	float x,y;	
};

// O(1)
float area(Point a, Point b, Point c){
	return (a.x*(b.y-c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y))/2.0f;
}

// O(N)
float calculateAreaOfHull(Point* hull,int N){
	float sum = 0;
	for(int i = 1; i < N - 1; i++)
		sum += abs(area(hull[0],hull[i],hull[i+1])); // O(1)
	return sum;
}

int main(){
	// Square with 1 unit area
	Point test1[4] = {{0,0},{0,1},{1,0},{1,1}};
	cout<<calculateAreaOfHull(test1,4)<<endl;
	
	// Rohmbus with 1 unit area
	Point test2[4] = {{0,0},{1,1},{1,0},{2,1}};
	cout<<calculateAreaOfHull(test2,4)<<endl;
	
	// Hexagon
	Point test3[6] = {{0,0},{1,0},{2,1},{1,2},{0,2},{-1,1}};
	cout<<calculateAreaOfHull(test3,6)<<endl;
	
	return 0;
}