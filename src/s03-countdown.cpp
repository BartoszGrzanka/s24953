#include <iostream>
#include <string>
#include <cstdlib>
auto main(int argc , char * argv[])->int
{
	
	auto temp = argv[1];
	if(temp){
	auto const a = std::atoi(temp);
	if(a<0){
	for(int i=a;i<=0;i++)
    	{
        std::cout << i << "\n";
    	}
	}
    else if(a>0){
	for(int i=a;i>=0;i--)
    {
        std::cout << i << "\n";
    }
	}
    else{
        std::cout << 0 << "\n";
	}}
	else{
	std::cout << "Podaj liczbe \n";
	}
    return 0;
}
