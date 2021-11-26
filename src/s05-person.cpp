#include <iostream>
#include <string>

//Osoby i tytuły
class Person{
	protected:
	std::string imie;
	std::string nazwisko;
	public:
	Person(std::string name, std::string surname) : imie(name), nazwisko(surname){}
	
	virtual std::string to_string() const = 0;

};

class Mr : public Person{
	public:
	Mr(std::string name, std::string surname) : Person(name, surname)
	{}
	auto to_string() const -> std::string{
		return "Mr " + imie + " " + nazwisko + "\n";
	}
};

class Mrs : public Person{
	public:
	Mrs(std::string name, std::string surname) : Person(name, surname)
	{}
	auto to_string() const -> std::string{
		return "Mrs " + imie + " " + nazwisko + "\n";
	}
};

class King : public Person{
	public:
	King(std::string name, std::string surname) : Person(name, surname)
	{}
	auto to_string() const -> std::string{
		return "King " + imie + " " + nazwisko + "\n";
	}
};

class Queen : public Person{
	public:
	Queen(std::string name, std::string surname) : Person(name, surname)
	{}
	auto to_string() const -> std::string{
		return "Queen " + imie + " " + nazwisko + "\n";
	}
};

auto who_is_it(Person const& x)->std::string
{
	return x.to_string();
}

//Powitania

class Greeting
{
	public:
	virtual std::string greet(Person const& x) = 0;
};

class Hello : public Greeting{
	std::string greet(Person const& x){
		return "Hello " + x.to_string();
	}
};

class Good_evening : public Greeting{
	std::string greet(Person const& x){
		return  "Good evening " + x.to_string();
	}
};

class Farewell : public Greeting{
	std::string greet(Person const& x){
		return "Farewell " + x.to_string();
	}
};
auto main() -> int
{
	Person* a = new Mr("AAA","aaa");
	Person* b = new Mrs("BBB","bbb");
	Person* c = new King("CCC","ccc");
	Person* d = new Queen("DDD","ddd");
	std::cout << who_is_it(*a) << "\n";
	std::cout << who_is_it(*b) << "\n";
	std::cout << who_is_it(*c) << "\n";
	std::cout << who_is_it(*d) << "\n";
	Greeting* hello = new Hello();
	Greeting* evening = new Good_evening();
	Greeting* farewell = new Farewell();
	std::cout << hello->greet(*a) << "\n";
	std::cout << hello->greet(*b) << "\n";
	std::cout << evening->greet(*c) << "\n";
	std::cout << farewell->greet(*d) << "\n";
}

