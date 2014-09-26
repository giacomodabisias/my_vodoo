#include <iostream>
#include <vector>

template<size_t ... args>
class caller {
	public:
	template<typename F, typename C>
	auto call(F f,C c) -> decltype(f(c.at(args) ...))
	{
		return f(c.at(args) ...);
	} 
};


int test(int a, int b, int c){

	return a+b+c;
}

int main () {

	std::vector<int> v = {1,4,7,3,9,6,4,8};
	caller<1,2,3> c;
	std::cout << "result: " << c.call(test, v) << std::endl;

}