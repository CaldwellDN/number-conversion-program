#include <stdio.h>
#include <stdlib.h>

int main() {
    char num[]="3076";
    long n = strtol(num, NULL, 16);
    printf("n=%ld\n", n);  // prints 12406

    return 0;
}