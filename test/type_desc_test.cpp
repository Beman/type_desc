#include <iostream>
#include <typeinfo>
#include <string>
#include "type_desc.hpp"

//void f(const int& x)
//{
//  std::cout << type_desc<decltype(x)>() << std::endl;
//}

int main()
{
  //std::cout << typeid(int).name() << std::endl;
  //std::cout << typeid(const int).name() << std::endl;
  //std::cout << typeid(int&).name() << std::endl;
  //std::cout << typeid(int*).name() << std::endl;

  //std::string s;
  //std::cout << typeid(decltype( s.begin())).name() << std::endl;

  std::cout << type_desc<int>() << std::endl;
  std::cout << type_desc<const int>() << std::endl;
  std::cout << type_desc<volatile int>() << std::endl;
  std::cout << type_desc<const volatile int>() << std::endl;
  std::cout << type_desc<int*>() << std::endl;
  std::cout << type_desc<int&>() << std::endl;
  std::cout << type_desc<int&&>() << std::endl;
  std::cout << type_desc<const int*>() << std::endl;
  std::cout << type_desc<const int&>() << std::endl;
  std::cout << type_desc<const volatile int&&>() << std::endl;
  std::cout << type_desc<int const*>() << std::endl;
  std::cout << type_desc<int const&>() << std::endl;
  std::cout << type_desc<int const&&>() << std::endl;
  std::cout << "----------\n";
  std::cout << type_desc<int* const>() << std::endl;
  std::cout << type_desc<const int* const>() << std::endl;
  std::cout << type_desc<const int**>() << std::endl;
  std::cout << type_desc<int[5]>() << std::endl;

  const int&& foo();
  std::cout << type_desc<decltype(foo())>() << std::endl;

//  f(5);
  return 0;
}
