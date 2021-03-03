#include <unistd.h>
#include <iostream>

int main(int, char**) {
    int count = 100;
    setbuf(stdout, NULL);
    for (size_t i = 0; i < count; i++)
    {
        printf("Hello world #%d!\n",i);
        usleep(10000);
    }

    return 0;
    
}
