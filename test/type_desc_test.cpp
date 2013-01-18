#include <iostream>
#include <typeinfo>
#include <string>
#include <boost/type_traits/type_desc.hpp>
#include <boost/detail/lightweight_main.hpp>
#include <boost/detail/lightweight_test.hpp>

using boost::type_desc;

//void f(const int& x)
//{
//  std::cout << type_desc<decltype(x)>() << std::endl;
//}

int cpp_main(int argc, char* argv[])
{
/*
  Examples taken from [dcl.ptr]

    int i;                       // an integer
    int *p;                      // a pointer to integer
    int *const cp = &i;          // a constant pointer to integer
    const int ci = 10            // a constant integer
    const int *pc = &ci;         // a pointer to a constant integer
    const int *const cpc = pc;   // a constant pointer to a constant integer
    const int **ppc;             // a pointer to a pointer to a constant integer
*/

  BOOST_TEST_EQ(type_desc<int>(), "<int>");
  BOOST_TEST_EQ(type_desc<int*>(), "<int*>");

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
  return boost::report_errors();
}
