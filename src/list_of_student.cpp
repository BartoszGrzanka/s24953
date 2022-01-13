#include <iostream>
#include <string>
#include <sstream>
#include <vector>
struct Student{
	std::string imie;
	std::string nazwisko;
	std::string indeks;
	int semestr;
	float srednia;
	Student(std::string i,std::string n,std::string in,int se, float sr){
		imie = i;	
		nazwisko = n;
		indeks = in;
		semestr = se;
		srednia = sr;
	}
	auto to_string()-> std::string
    {
        auto wynik = std::ostringstream{};
		wynik << imie <<" "<<nazwisko << "("<<indeks<<") semestr " << semestr << " średnia "<< srednia;
		return wynik.str();    
    }
	};
	struct lista{
    std::string name;
    std::vector<Student> members;

    lista(std::string const& n) {
        name = n;
    }

    auto add_student(Student const& s) -> void{
        members.push_back(s);
    }

    auto display() -> void {
        std::cout << name << ": \n";
        for (auto const& stud : members){
            std::cout << stud.imie <<" "<<stud.nazwisko << "("<<stud.indeks<<") semestr " << stud.semestr << " średnia "<< stud.srednia<<"\n";;

        }
    }
	
	auto del_student(int numb) -> void{
        members.erase(members.begin()+(numb - 1));
    }

};



auto main() -> int
{
    auto s1 = Student{"Bartosz","Grzanka","s24953",1,0};
	auto s2 = Student{"Bbbb","Gggg","s00000",10,22};
    std::cout<<s1.to_string()<<"\n"; 
	std::cout<<s2.to_string()<<"\n"; 
	auto lista1 = lista("moja_lista1");
	auto lista2 = lista("moja_lista2");
	lista1.add_student(s1);
	lista1.add_student(s2);
	lista1.display();
	lista1.del_student(1);
	lista1.display();
    return 0;
}