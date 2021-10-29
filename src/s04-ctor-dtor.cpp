#include <iostream>
#include <string>

struct Super{
    
    std::string zmienna;
    Super(std::string a){
	zmienna = a;
	std::cout << zmienna <<"\n";
    }
    
    ~Super(){
	zmienna = "DESTRUCTION!";
	std::cout <<zmienna <<"\n";
    }
};


int main(){
    Super a("Stworzono");
    
}
