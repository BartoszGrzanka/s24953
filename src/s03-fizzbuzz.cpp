#include <iostream>
#include <string>

auto main(int argc , char * argv[])->int
{
	auto temp = argv[1];
	if(temp){
	auto const a = std::atoi(temp);
	if(a>0){
	for(int i=1;i<=a;i++)
    	{
           std::cout<<i<<" ";
           if(i%3==0)
            {
                if(i%5==0)
                {
                std::cout<<"FizzBuzz \n";
                }
                else
                {
                std::cout<<"Fizz \n";
                }
            }
            else if(i%5==0)
            {
           std::cout<<"Buzz \n";
            }
        else{
        std::cout << " \n";
        }

        
    	}
	}}
    else{
    std::cout << "Podaj liczbe \n";
	}
return 0;
}
