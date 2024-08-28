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

  //std::vector<char> v1(p);
  std::vector<char> v2(p, p+sz);

  std::vector<char> v3;
  v3.insert(v3.end(), p, p+sz);

  //std::vector<char> v4(v2.data(), v2.size());
  printf("p=");
  for (int i = 0; i < strlen(p); i++) {
        std::cout << p[i];
    }
  std::cout << std::endl;
  //std::cout << "v1="<< std::string(v1.begin(), v1.end()) << std::endl;
  printf("v2=");
  for (char c : v2) {
        std::cout << c;
    }
    std::cout << std::endl;
  printf("v3=");
  for (char c : v3) {
        std::cout << c;
    }
    std::cout << std::endl;
  //std::cout << "v4="<< std::string(v4.begin(), v4.end()) << std::endl;

  std::vector<char> pbinario = { 'h', '\0', 'o', '\0', 'l', '\0', 'a', '\0', ' ', '\0', 'm', '\0', 'u', '\0', 'n', '\0', 'd', '\0', 'o', '\0' };
  p = &pbinario[0];
  //std::vector<char> v5(p);
  std::vector<char> v6(p, p+sz);

  std::vector<char> v7;
  v7.insert(v7.end(), p, p+sz);

  //std::vector<char> v8(v6.data(), v6.size());

  printf("p=");
  for (int i = 0; i < strlen(p); i++) {
        std::cout << p[i];
    }
  std::cout << std::endl;
  //std::cout << "v1="<< std::string(v5.begin(), v5.end()) << std::endl;
  printf("v2=");
  for (char c : v6) {
        std::cout << c;
    }
  std::cout << std::endl;
  printf("v3=");
  for (char c : v7) {
        std::cout << c;
    }
  std::cout << std::endl;
  //std::cout << "v4="<< std::string(v8.begin(), v8.end()) << std::endl;

  std::vector<char> pbinario2 = { 'h', 'o', 'l', 'a', ' ', 'm', 'u', 'n', 'd', 'o' };
  p = &pbinario2[0];
  //std::vector<char> v9(p);
  std::vector<char> v10(p, p+sz);

  std::vector<char> v11;
  v11.insert(v11.end(), p, p+sz);

  //std::vector<char> v12(v10.data(), v10.size());

  printf("p=");
  for (int i = 0; i < strlen(p); i++) {
        std::cout << p[i];
    }
  std::cout << std::endl;
  //std::cout << "v1="<< std::string(v9.begin(), v9.end()) << std::endl;
  printf("v2=");
  for (char c : v10) {
        std::cout << c;
    }
  std::cout << std::endl;
  printf("v3=");
  for (char c : v11) {
        std::cout << c;
    }
  std::cout << std::endl;
  //std::cout << "v4="<< std::string(v12.begin(), v12.end()) << std::endl;
  return 0;
}
