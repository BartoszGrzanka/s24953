#include <iostream>
#include <string>
#include <sstream>

struct Time
{
	int hour = 0;
	int minute = 0;
	int second = 0;

	
	Time(int h, int m, int s){
		hour = h;
		minute = m;
		second = s;				
	}


	auto next_hour()-> void
	{
		if(hour == 23)
		{
			hour = 0;			
		}
		else{
			hour++;		
		}	
	}

	auto next_minute()-> void
	{
		if(minute == 59)
		{
			minute = 0;
			next_hour();			
		}
		else{
			minute++;		
		}	
	}

	auto next_second()-> void
	{
		if(second == 59)
		{
			second = 0;
			next_minute();			
		}
		else{
			second++;		
		}	
	}

	auto to_string() const -> std::string{
		auto out = std::ostringstream{};
		if(hour < 10){
		out << "0"<<hour<<";";		
		}
		else{
		out<<hour<<":";		
		}
		if(minute < 10){
		out << "0"<<minute<<";";		
		}
		else{
		out<<minute<<":";		
		}
		if(second < 10){
		out << "0"<<second<<";";		
		}
		else{
		out<<second<<":";		
		}
		return out.str();
	}
};


auto main()-> int
{

	auto t1 = Time(23,59,59);
	std::cout << t1.to_string()<<"\n";
	int mili =1000;	
	
	while(true){
	t1.next_second();
	std::cout << t1.to_string()<<"\n";
	}
}
