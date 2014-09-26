#include "template_model_test.hpp"

extern template class test<double>; 

int main (){
	
	test<int> one;
	test<double> two;
	one.print(2.5);
	two.print(2.5);

	return 0;
}