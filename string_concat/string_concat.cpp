#include <sstream>
#include <iostream>
#include <type_traits>

class MyClass{
public:
	std::string s;
	MyClass():s("myclass"){}
};

std::ostream&
operator<<(std::ostream& ss, MyClass & a){
	return ss << a.s;
}

template <class T>
struct IsMyClass {
};

template <>
struct IsMyClass<MyClass> {
  static const bool value = true;
};

template<class T>
struct IsStreamable{

	enum{value = std::is_arithmetic<T>::value ||
         std::is_same<T, std::string>::value ||
         IsMyClass<MyClass>::value
        };
};

template<class X>
std::string
static ToString(X & x){
	std::ostringstream os;
	os << x;
	return os.str();
}

template <class X, class Y>
struct CanConcat{
	enum{ value = std::is_same<X, std::string>::value && IsStreamable<Y>::value ||
		  std::is_same<Y, std::string>::value && IsStreamable<X>::value};
		  
};

template <class X, class Y>
typename std::enable_if<CanConcat<X,Y>::value, std::string>::type
operator+(X x, Y y){

	return ToString(x) + ToString(y);
}

int main(){
	std::string s("hello");
	std::string a("world");
	MyClass m;
	bool t = true;
	std::cout << s + " " + a + " " + 42 + " " + m + " " + t << std::endl;
}