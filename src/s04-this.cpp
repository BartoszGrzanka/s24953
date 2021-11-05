#include <iostream>

struct dis
{

	void cos(){
			std::cout << this << std::endl;
	}
};


auto main()-> int
{
	struct dis x;
    x.cos();
    std::cout << &x << std::endl;    

	return 0;
}
