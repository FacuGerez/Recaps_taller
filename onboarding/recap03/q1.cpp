#include <iostream>

int main () {
  std::string foo = "hola mundo";
  std::string bar = foo.substr(2, 4);
  std::cout << bar << std::endl;
  return 0;
}
