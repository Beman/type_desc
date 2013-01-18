//  boost/type_traits/type_desc.hpp  -------------------------------------------------//  

//  Copyright Beman Dawes 2010

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef BOOST_TYPE_TRAITS_TYPE_DESC_HPP
#define BOOST_TYPE_TRAITS_TYPE_DESC_HPP

#include <boost/config.hpp>

#include <string>
#include <boost/type_traits/is_const.hpp>
#include <boost/type_traits/is_volatile.hpp>
#include <boost/type_traits/is_pointer.hpp>
#include <boost/type_traits/is_lvalue_reference.hpp>
#include <boost/type_traits/is_rvalue_reference.hpp>
#include <boost/type_traits/remove_pointer.hpp> 
#include <boost/type_traits/remove_reference.hpp> 
#include <boost/detail/scoped_enum_emulation.hpp>

/*
  Examples taken from [dcl.ptr]

    const int ci = 10            // a constant integer
    const int *pc = &ci;         // a pointer to a constant integer
    const int *const cpc = pc;   // a constant pointer to a constant integer
    const int **ppc;             // a pointer to a pointer to a constant integer
    int i;                       // an integer
    int *p;                      // a pointer to integer
    int *const cp = &i;          // a constant pointer to integer
*/

namespace boost
{
  BOOST_SCOPED_ENUM_DECLARE_BEGIN(description_options)
  { none, bracket }; 
  BOOST_SCOPED_ENUM_DECLARE_END(description_options)

template <class T>
std::string type_desc(BOOST_SCOPED_ENUM(description_options)
                        opts = description_options::bracket)
{
  std::string s;

  if (std::is_pointer<T>::value)
  {
  //std::cout << "ptr: ";
    if (boost::is_const<typename boost::remove_pointer<T>::type>::value)
      s += "const ";
    if (boost::is_volatile<typename boost::remove_pointer<T>::type>::value)
      s += "volatile ";
      
    if (opts == description_options::bracket)
      s += '<';
    s += typeid(typename boost::remove_pointer<T>::type).name();
    if (opts == description_options::bracket)
      s += '>';
    s += "*";
    
    if (boost::is_const<T>::value)
      s += " const";
    if (boost::is_volatile<T>::value)
      s += " volatile";
  }
  else // not a pointer
  {
    if (boost::is_const<typename boost::remove_reference<T>::type>::value)
      s += "const ";
    if (boost::is_volatile<typename boost::remove_reference<T>::type>::value)
      s += "volatile ";

    if (opts == description_options::bracket)
      s += '<';
    s += typeid(typename boost::remove_pointer<T>::type).name();
    if (opts == description_options::bracket)
      s += '>';

    if (boost::is_lvalue_reference<T>::value)
      s += "&";
    if (boost::is_rvalue_reference<T>::value)
      s += "&&";
  }
 
  return s;
}

}  // namespace boost

#endif  // include guard
