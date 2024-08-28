#include <cstring>

int main(int argc, char* argv[]) {
    char otherbuf[40] = "This is a test about how to use it";
    char buf[5];
    strcpy(buf, otherbuf);
    return 0;
}
