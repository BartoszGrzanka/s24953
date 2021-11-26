#ifndef TIMEH
#define TIMEH
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
	Time() = default;
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
		out<<second;		
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

	auto operator+ (Time const& o) const -> Time{
		int h = hour;
		int m = minute;
		int s = second;
		s += o.second;
		if(s > 59){
			s-=60;
			m++;
		}
		m += o.minute;
		if(m > 59){
			m -=60;
			h++;
		}
		h += o.hour;
		if(h > 23){
			h-=24;
		}
		return Time(h,m,s);
	}

	
	auto operator- (Time const& o) const -> Time{
		int h = hour;
		int m = minute;
		int s = second;
		s -= o.second;
		if(s < 0){
			s+=60;
			m--;
		}
		m -= o.minute;
		if(m < 0){
			m +=60;
			h--;
		}
		h -= o.hour;
		if(h < 0){
			h +=24;
		}
		return Time(h,m,s);
	}
	auto operator< (Time const& o) const -> bool{
		if(hour < o.hour){
			return true;	
		}
		if(hour != o.hour){
			return false;	
		}
		if(minute < o.minute){
			return true;	
		}
		if(minute != o.minute){
			return false;	
		}
		if(second < o.second){
			return true;	
		}
		if(second != o.second){
			return true;	
		}
		return false;
	}
	auto operator> (Time const& o) const -> bool{
		if(hour > o.hour){
			return true;	
		}
		if(hour != o.hour){
			return false;	
		}
		if(minute > o.minute){
			return true;	
		}
		if(minute != o.minute){
			return false;	
		}
		if(second > o.second){
			return true;	
		}
		if(second != o.second){
			return false;	
		}
		return false;
	}
	auto operator== (Time const& o) const -> bool{
		return (hour == o.hour && minute == o.minute && second == o.second);
	}
	auto operator!= (Time const& o) const -> bool{
		return !(hour == o.hour && minute == o.minute && second == o.second);
	}

	auto count_seconds() const -> uint64_t{
		std::uint64_t count = 0;
		count += hour * 60 * 60;
		count += minute * 60;
		count += second;
		return count;	
	}
	auto count_minutes() const -> uint64_t{
		std::uint64_t count = 0;
		count += hour * 60;
		count += minute;
		return count;	
	}
	auto time_to_midnight() const -> Time{
		Time time;
		if(second == 0){
			time.second = second;
			time.minute = 60 - minute;
		}
		else{
			time.minute = 59- minute;
			time.second = 60 - second;
		}		
			time.hour = 23 - hour;		
	
		return time;
	}

};
#endif 
