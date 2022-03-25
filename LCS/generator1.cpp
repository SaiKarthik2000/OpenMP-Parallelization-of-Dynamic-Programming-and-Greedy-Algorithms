#include <ctime>
#include <iostream>
#include <unistd.h>
using namespace std;
int main(int argc, char *argv[]) {
    srand((unsigned)time(NULL) * getpid());    
    freopen ("Test_Cases_1.txt", "w", stdout); 
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < 10000; ++i) {
        printf("%c",alphanum[rand() % (sizeof(alphanum) - 1)]);
    }
    printf("\n");
    for (int i = 0; i < 10000; ++i) {
        printf("%c",alphanum[rand() % (sizeof(alphanum) - 1)]);
    }
    fclose(stdout);
    return 0;
}
