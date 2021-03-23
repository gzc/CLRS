/*
 * Program:
 *		solve exercise 1.2-3
 * Release:
 *		2018/05/30	ZhangDao	First release
 */
#include <iostream>
#include <cmath>

int main()
{
	// to avoid endless loop
	int maxNumber = 100;
	for (int i = 1; i < maxNumber; ++i)
	{
		if ((100 * i * i) < pow(2, i))
		{
			std::cout << i << std::endl;
			return 0;
		}
	}
	return 0;
}
