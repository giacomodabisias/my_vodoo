
#include <iostream>
#include <type_traits>

template <class T>
struct is_pointer{

	template <class S>
	static char is_ptr( S * );

	template <class F, class J>
	static char is_ptr(F J::*);

	template <class U>
	static char is_ptr(U (*) ());

	static double is_ptr(...);

	static T  t;
	enum{ value = sizeof(is_ptr(t)) == sizeof(char)};
};

int main(){
	
typedef int *  ptr;
if (is_pointer<ptr>::value)
	std::cout << "is pointer" << std::endl;
else
	std::cout << "is not pointer" << std::endl;

}