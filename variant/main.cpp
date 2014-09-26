// "<Copyright 2014 Giacomo Dabisias>"


#include "variant.hpp"


int main() {
Variant<int, double, float> my_variant;
my_variant.PrintInfo();
std::cout << "int is number " << my_variant.FindIdxByType<int>() << " in list " << std::endl;
std::cout << "double is number " << my_variant.FindIdxByType<double>() << " in list " << std::endl;
std::cout << "float is number " << my_variant.FindIdxByType<float>() << " in list " << std::endl;
std::cout << "bool is number " << my_variant.FindIdxByType<bool>() << " in list " << std::endl;

std::cout << "number one is " << my_variant.FindTpByIndex<0>() << std::endl;
std::cout << "number two is " << my_variant.FindTpByIndex<1>() << std::endl;
std::cout << "number three is " << my_variant.FindTpByIndex<2>() << std::endl;
std::cout << "number four is " << my_variant.FindTpByIndex<3>() << std::endl;


int d;
std::cin >> d;
if(d)
	my_variant = static_cast<int>(42);
else
	my_variant = static_cast<double>(3.14);


std::cout << "data contained is " << my_variant.GetDataByType<int>() << std::endl;


}
