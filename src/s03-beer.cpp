#include <iostream>
#include <string>

auto main(int argc, char *argv[])->int{
    auto norm = 99;
    if(argc == 2){
        auto const temp = std::stoi (argv[1]);
        if(temp<0 || temp==0){
            std::cout<<"Negative number or zero\n";
            return 1;        
        }
    norm = temp;
    }
    for(int i = norm;i > 1;--i){
        std::cout << i << " bottles of beer on the wall, " << i << " bottles of beer.\n";
        if(i == 2){
            std::cout << "Take one down, pass it around, " << i-1 << " bottle of beer on the wall...\n";
            std::cout << "1 bottle of beer on the wall, 1 bottle of beer.\nTake one down and pass it around, no more bottles of beer on the wall\n";       
        }
        else{
            std::cout << "Take one down, pass it around, " << i-1 << " bottles of beer on the wall...\n";
        }
    }

    std::cout << "No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, "<< norm <<" bottles of beer on the wall... \n";



return 0;
}
