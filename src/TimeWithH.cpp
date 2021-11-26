#include "ttime.h"
#include <iostream>
#include <string>
#include <sstream>

auto main()-> int
{

	auto t1 = Time(23,59,59);
	std::cout << t1.to_string()<<"\n";
	t1.next_second();
	std::cout << t1.to_string()<<"\n";
	std::cout << t1.to_string(t1.time_of_day()) << "\n";
	auto x = t1 + Time(1, 30, 20);
	auto y = x - Time(0,20,1);
	auto z = x == y;
	std::cout << x.to_string() << "\n";
	std::cout << y.to_string() << "\n";
	std::cout << z << "\n";
	auto t2 = Time(22,12,33);
	std::cout << "seconds: " << t2.count_seconds() << "\n";
	std::cout << "minutes: " << t2.count_minutes() << "\n";
	std::cout << "to midnight: " << t2.time_to_midnight().to_string() << "\n";
	return 0;
}

