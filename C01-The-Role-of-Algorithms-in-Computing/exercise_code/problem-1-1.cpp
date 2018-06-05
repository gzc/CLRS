/*
 * Program:
 *		solve exercise 1.2-4
 * Release:
 *		2018/05/30	ZhangDao	First release
 */
#include <iostream>
#include <vector>
#include <cmath>

int main()
{
	// init time
	std::vector<long> time(7, 60);// time "century" may be bigger than INT_MAX
	time[1] = time[0] * 60;
	time[2] = time[1] * 60;
	time[3] = time[2] * 24;
	time[4] = time[3] * 30;
	time[5] = time[4] * 12;
	time[6] = time[5] * 1000;

	// lg(n)
	std::cout << "~~~~~~~~~~~~~lg(n)~~~~~~~~~~~~~~~~~" << std::endl;
	for (auto c : time)
	{
		std::cout << pow(2, c) << std::endl;
	}

	// sqrt(n)
	std::cout << "~~~~~~~~~~~~~sqrt(n)~~~~~~~~~~~~~~~~~" << std::endl;
	for (auto c : time)
	{
		if ((c * c) > 0)
			std::cout << c * c << std::endl;
		else
			std::cout << "inf" << std::endl;
	}

	// n
	std::cout << "~~~~~~~~~~~~~n~~~~~~~~~~~~~~~~~" << std::endl;
	for (auto c : time)
	{
		std::cout << c << std::endl;
	}

	// nlg(n)
	std::cout << "~~~~~~~~~~~~~nlg(n)~~~~~~~~~~~~~~~~~" << std::endl;
	for (auto c : time)
	{
		long firstIndex = 1, lastIndex = c;
		long middleIndex;
		while(1)
		{
			middleIndex = (firstIndex + lastIndex) / 2;
			if ((lastIndex - firstIndex) <= 1)
			{
				std::cout << firstIndex << std::endl;
				break;
			}
			if ((middleIndex * log(middleIndex) / log(2)) > c)
			{
				lastIndex = middleIndex;
			}
			else
			{
				firstIndex = middleIndex;
			}
		}
	}

	// n^2
	std::cout << "~~~~~~~~~~~~~n^2~~~~~~~~~~~~~~~~~" << std::endl;
	for (auto c : time)
	{
		std::cout << static_cast<long>(sqrt(static_cast<double>(c))) << std::endl;
	}

	// n^3
	std::cout << "~~~~~~~~~~~~~n^3~~~~~~~~~~~~~~~~~" << std::endl;
	for (auto c : time)
	{
		std::cout << static_cast<long>(pow(c, 1.0 / 3)) << std::endl;
	}

	// 2^n
	std::cout << "~~~~~~~~~~~~~2^n~~~~~~~~~~~~~~~~~" << std::endl;
	for (auto c : time)
	{
		std::cout << static_cast<long>(log(c) / log(2)) << std::endl;
	}

	// n!
	std::cout << "~~~~~~~~~~~~~n!~~~~~~~~~~~~~~~~~" << std::endl;
	for (auto c : time)
	{
		for(long i = 1, count = 1;;)
		{
			if (count > c)
			{
				std::cout << (i - 1) << std::endl;
				break;
			}
			else
			{
				++i;
				count *= i;
			}
		}
	}

	return 0;
}
