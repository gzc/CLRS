/*************************************************************************
    > File Name: weighted_activity_selection.h
    > Author: Nikolaus Fedurko (@B1Z0N)
    > Mail: 
    > Created Time: Wed 3 Aug 2019 02:16:46 PM CST
 ************************************************************************/
#include "weighted_activity_selection.h"

 #include <iostream>


void test( int real, int expected) {
	if ( real == expected )
		std::cout << "Success!\n";
	else
		std::cout << "Error: " << real << " != " << expected << '\n';
}

int main( ) {
// Base cases
    test(weighted_activity( { 1 }, { 2 }, { 3 } ), 3);
    test(weighted_activity( { 1, 3 }, { 3, 5 }, { 1, 2 } ), 3);

// Medium cases
    test(weighted_activity( { 1, 3, 6, 2}, 
                               { 2, 5, 19, 100 }, 
                               { 50, 20, 100, 200 } ), 250);
    test(weighted_activity( { 5, 3, 10, 8, 3, 8, 8, 8, 10, 10 }, 
                               { 6, 5, 11, 9, 9, 9,10, 9, 11, 11 }, 
                               { 10, 4, 10, 5, 8, 5, 4, 3, 2, 1  } ), 29);
}