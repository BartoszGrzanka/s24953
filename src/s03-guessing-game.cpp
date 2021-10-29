#include <iostream>
#include <string>
#include <stdlib.h>

auto main() -> int 
{
    int liczba_losowa;
    auto strzal = std::string{};
    srand(time(NULL));
    liczba_losowa = rand()%100+1;
    do
    {
        std::cout<<"sprobuj zgadnac liczbe \n";
        std::getline(std::cin, strzal);
        auto a = std::stoi(strzal);
        if(liczba_losowa==a)
        {
            std::cout<<"zgadles BRAWO \n";
            break;
        }
        else if(liczba_losowa>a)
        {
            std::cout<<"troche wiecej \n";
        }
        else
        {
            std::cout<<"troche mniej \n";
        }
    }
    while(true);
}
