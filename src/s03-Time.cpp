#include <iostream>
#include <string>
#include <sstream>

struct Time
{
	int hour = 0;
	int minute = 0;
	int second = 0;
	enum Time_of_day{
	morning, 
	afternoon, 
	evening, 
	night,
	};
	
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



	auto to_string(Time_of_day x) const ->std::string
	{
		switch(x){
		case morning:
		return "morning";
		case afternoon:
		return "afternoon";
		case evening:
		return "evening";
		case night:
		return "night";
		default:
			throw "Error";
		};
	}
	auto time_of_day() const -> Time_of_day{
		
		if(hour >= 6 && hour <=11){
			return morning;		
		}
		else if(hour >= 12 && hour <= 16){
			return afternoon;		
		}
		else if(hour >= 17 && hour <= 20){
			return evening;		
		}
		else{
			return night;
		}
	}
};


auto main()-> int
{

	auto t1 = Time(23,59,59);
	std::cout << t1.to_string()<<"\n";
	t1.next_second();
	std::cout << t1.to_string()<<"\n";
	std::cout << t1.to_string(t1.time_of_day()) << "\n";

}
