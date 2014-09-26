#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>

template <typename one>
void out(one o) {
	
	std::cout << typeid(o).name() << std::endl;
}

template <typename first, typename ... args>
void out(first f, args ... a) {
	
	std::cout << typeid(f).name() << std::endl;
	out(a...);
}



int main(){
	
	int par_a = 5;
	int par_b = 6;
	double par_c = 4;
	std::string par_s;

	out(par_a,par_b,par_c, par_s);

}


