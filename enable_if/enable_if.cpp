
#include <iostream>
#include <type_traits>

template <class T, class L = typename std::enable_if<std::is_integral<T>::value, T>::type  > //without L it becomes an anonymus template argument for type checking
typename std::enable_if<std::is_integral<T>::value, T>::type 
foo(T t)
{
  L f = 5;
  t+=f;
  return t;
}

int main(){
	
std::cout << foo(3) <<std::endl;

}