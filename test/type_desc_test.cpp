//  type_desc_test.cpp  ----------------------------------------------------------------//  

//  Copyright Beman Dawes 2013

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <iostream>
#include <typeinfo>
#include <string>
#include <boost/type_traits/type_desc.hpp>
#include <boost/detail/lightweight_main.hpp>

#define BOOST_LIGHTWEIGHT_TEST_OSTREAM std::cout
#include <boost/detail/lightweight_test.hpp>

using boost::type_desc;
using std::cout;
using std::endl;

#if defined(BOOST_GCC)
# define PRINT_TYPEID_NAME(T) cout << #T " : " << abi::__cxa_demangle(typeid(T).name(), NULL, NULL, NULL) \
  << " " << boost::is_const<typename boost::remove_reference<T>::type>::value << endl;
#else
# define PRINT_TYPEID_NAME(T) cout << #T " : " << typeid(T).name() \
  << " " << boost::is_const<typename boost::remove_reference<T>::type>::value << endl;
#endif

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

  // non-pointer types

  cout << "\nnon-pointer types\n"
          "=================\n";

  PRINT_TYPEID_NAME(int);
  BOOST_TEST_EQ(type_desc<int>(), "int");

  PRINT_TYPEID_NAME(const int);
  BOOST_TEST_EQ(type_desc<const int>(), "const int");

  PRINT_TYPEID_NAME(int const);
  BOOST_TEST_EQ(type_desc<int const>(), "const int");

  PRINT_TYPEID_NAME(int&);
  BOOST_TEST_EQ(type_desc<int&>(), "int&");

  PRINT_TYPEID_NAME(const int&);
  BOOST_TEST_EQ(type_desc<const int&>(), "const int&");

  PRINT_TYPEID_NAME(int const&);
  BOOST_TEST_EQ(type_desc<int const&>(), "const int&");

  PRINT_TYPEID_NAME(int&&);
  BOOST_TEST_EQ(type_desc<int&&>(), "int&&");

  PRINT_TYPEID_NAME(const int&&);
  BOOST_TEST_EQ(type_desc<const int&&>(), "const int&&");

  PRINT_TYPEID_NAME(int const&&);
  BOOST_TEST_EQ(type_desc<int const&&>(), "const int&&");

// pointer types

  cout << "\npointer types\n"
          "=============\n";

  PRINT_TYPEID_NAME(int*);
  BOOST_TEST_EQ(type_desc<int*>(), "int*");

  PRINT_TYPEID_NAME(const int*);
  BOOST_TEST_EQ(type_desc<const int*>(), "const int*");

  PRINT_TYPEID_NAME(int const*);
  BOOST_TEST_EQ(type_desc<int const*>(), "const int*");

  PRINT_TYPEID_NAME(const int* const);
  BOOST_TEST_EQ(type_desc<const int* const>(), "const int* const");

  PRINT_TYPEID_NAME(int const* const);
  BOOST_TEST_EQ(type_desc<int const* const>(), "const int* const");

  PRINT_TYPEID_NAME(const int **);
  BOOST_TEST_EQ(type_desc<const int **>(), "const int**");

  PRINT_TYPEID_NAME(int const**);
  BOOST_TEST_EQ(type_desc<int const**>(), "const int**");

  PRINT_TYPEID_NAME(int const** const);
  BOOST_TEST_EQ(type_desc<int const** const>(), "const int** const");

  PRINT_TYPEID_NAME(int const* const * const);
  BOOST_TEST_EQ(type_desc<int const* const * const>(), "const int* const* const");


  const int&& foo();
  cout << type_desc<decltype(foo())>() << endl;

//  f(5);
  return boost::report_errors();
}
