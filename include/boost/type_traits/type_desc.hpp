#include <string>
#include <type_traits>

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

template <class T>
std::string type_desc()
{
  std::string s;

  if (std::is_pointer<T>::value)
  {
  //std::cout << "ptr: ";
    if (std::is_const<typename std::remove_pointer<T>::type>::value)
      s += "const ";
    if (std::is_volatile<typename std::remove_pointer<T>::type>::value)
      s += "volatile ";
      
    s += '<';
    s += typeid(typename std::remove_pointer<T>::type).name();
    s += '>';
    s += "*";
    
    if (std::is_const<T>::value)
      s += " const";
    if (std::is_volatile<T>::value)
      s += " volatile";
  }
  else // not a pointer
  {
    if (std::is_const<typename std::remove_reference<T>::type>::value)
      s += "const ";
    if (std::is_volatile<typename std::remove_reference<T>::type>::value)
      s += "volatile ";

    s += '<';
    s += typeid(typename std::remove_pointer<T>::type).name();
    s += '>';

    if (std::is_lvalue_reference<T>::value)
      s += "&";
    if (std::is_rvalue_reference<T>::value)
      s += "&&";
  }
 
  return s;
}
