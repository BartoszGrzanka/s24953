#include <iostream>
#include <string>

auto main(int argc , char * argv[])->int
{
	auto temp = argv[1];
	if(temp){
	auto pass = std::string{};    
	do{
	std::cout << "Podaj hasło: \n";
        std::getline (std::cin, pass);
	}
	while(argv[1]!=pass);
	
	std::cout << "Ok \n";
	return 0;
	}
	else{
	std::cout << "Podaj hasło do sprawdzania śmieszku \n";
	}

}
