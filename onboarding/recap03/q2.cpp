#include <iostream>
#include <string>
#include <cstring>
#include <vector>

int main () {
  // Suponer que 'p' es un char* y que 'sz' es un size_t

  char* p;
  std::string pstring = "ho\0la mundo";

  p = &pstring[0];
  int sz = 4;
  std::string s1(p);
  std::string s2(p, sz);

  std::string s3;
  s3.append(p);

  std::string s4;
  s4.append(p, sz);

  std::string s5(p, strlen(p));



  std::string s6(p, sz);
  std::string s7(s6.c_str());

  std::cout << "p="<< p << std::endl;
  std::cout << "s1="<< s1 << std::endl;
  std::cout << "s2="<< s2 << std::endl;
  std::cout << "s3="<< s3 << std::endl;
  std::cout << "s4="<< s4 << std::endl;
  std::cout << "s5="<< s5 << std::endl;
  std::cout << "s6="<< s6 << std::endl;
  std::cout << "s7="<< s7 << std::endl;

  std::vector<char> pbinario = { 'h', '\0', 'o', '\0', 'l', '\0', 'a', '\0', ' ', '\0', 'm', '\0', 'u', '\0', 'n', '\0', 'd', '\0', 'o', '\0' };
  p = &pbinario[0];
  std::string s8(p);
  std::string s9(p, sz);

  std::string s10;
  s10.append(p);

  std::string s11;
  s11.append(p, sz);

  std::string s12(p, strlen(p));



  std::string s13(p, sz);
  std::string s14(s13.c_str());

  std::cout << "p="<< p << std::endl;
  std::cout << "s1="<< s8 << std::endl;
  std::cout << "s2="<< s9 << std::endl;
  std::cout << "s3="<< s10 << std::endl;
  std::cout << "s4="<< s11 << std::endl;
  std::cout << "s5="<< s12 << std::endl;
  std::cout << "s6="<< s13 << std::endl;
  std::cout << "s7="<< s14 << std::endl;

  std::vector<char> pbinario2 = { 'h', 'o', 'l', 'a', ' ', 'm', 'u', 'n', 'd', 'o' };
  p = &pbinario2[0];
  std::string s15(p);
  std::string s16(p, sz);

  std::string s17;
  s17.append(p);

  std::string s18;
  s18.append(p, sz);

  std::string s19(p, strlen(p));


  std::string s20(p, sz);
  std::string s21(s20.c_str());

  std::cout << "p="<< p << std::endl;
  std::cout << "s1="<< s15 << std::endl;
  std::cout << "s2="<< s16 << std::endl;
  std::cout << "s3="<< s17 << std::endl;
  std::cout << "s4="<< s18 << std::endl;
  std::cout << "s5="<< s19 << std::endl;
  std::cout << "s6="<< s20 << std::endl;
  std::cout << "s7="<< s21 << std::endl;
  return 0;
}
