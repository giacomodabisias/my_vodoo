#include <vector>
#include <cstdlib>
#include <iostream>

template <size_t... Args>
struct call_n_args
{
  template <typename F, typename Container>
  auto
  operator()(F f, const Container& c)
    -> decltype(f(c.at(Args)...))
  {
    return f(c.at(Args)...);
  }
};

template <typename F>
auto
foo(F f, const std::vector<int>& v)
  -> decltype(call_n_args<2,1,5,4>()(f, v))
{
  return call_n_args<2,1,5,4>()(f, v);
}

int
sum4(int a, int b, int c, int d)
{
  return a + b + c + d;
}

class test {
public:
  int a = 5;

  test(){}


};

int main()
{
  std::vector<int> v{3,4,5,6,7,8,9};
  call_n_args<2,1,5,4> s;
  test c;

  std::cout << foo(&sum4, v) <<std::endl; 
  std::cout << s(&sum4, v) <<std::endl;
}