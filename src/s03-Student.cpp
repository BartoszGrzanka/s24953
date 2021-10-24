
#include <iostream>
#include <string>
#include <sstream>
struct Student{
	private:
	std::string imie;
	std::string nazwisko;
	std::string indeks;
	int semestr;
	float srednia;
	public:
	Student(std::string i,std::string n,std::string in,int se, float sr){
		imie = i;	
		nazwisko = n;
		indeks = in;
		semestr = se;
		srednia = sr;
	}
	

	auto const to_string()-> std::string
    {
        auto wynik = std::ostringstream{};
	wynik << imie <<" "<<nazwisko << "("<<indeks<<") semestr " << semestr << " średnia "<< srednia;
	
	return wynik.str();    
    }

};



auto main() -> int
{
    auto s1 = Student{"Bartosz","Grzanka","s24953",1,0};
    std::cout<<s1.to_string()<<"\n"; 

    return 0;
}
