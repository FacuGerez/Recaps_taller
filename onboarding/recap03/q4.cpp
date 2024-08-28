#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

int main(){
    // ok, pero rapidamente tiene sus limitaciones
    std::string who = "Alice";
    who += " and ";
    who += "Bob";

    // mucho mas flexible ya q permite formatear a string
    // numeros en distintas bases (entre otras cosas)
    std::stringstream ss;
    ss << who << ": " << 42 << " (" << std::setbase(16) << 42 << ")";

    std::string msg = ss.str();

    std::cout << who << std::endl;
    std::cout << msg << std::endl;

    return 0;
}
