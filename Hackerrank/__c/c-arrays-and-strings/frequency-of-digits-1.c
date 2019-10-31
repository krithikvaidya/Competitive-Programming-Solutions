#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char str[1000];
    fgets(str, 1000, stdin); 

    int app[128] = { 0 };

    for(int i = 0; str[i] != '\0'; i++)
    {
        app[(int)str[i]]++;
    }

    for(int i = 48; i <= 57; i++)
        printf("%d ", app[i]);

    return 0;
}

