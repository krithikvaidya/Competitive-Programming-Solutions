#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char str[100000];
    int ctr=0,i;
    gets(str);
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i] == ' ')
            ctr++;
    }
    ctr++;
    int j=0,k=0;
    char words[ctr][100000];
    for(i=0;str[i]!='\0';i++)
    {
        words[j][k] = str[i];
        k++;
        if(str[i] == ' ')
        {
            j++;
            k=0;
        }
    }
    for(i=0;i<ctr;i++)
    {
        for(j=0;words[i][j]!='\0';j++)
            printf("%c", words[i][j]);
        printf("\n");
    }
    printf("haha");
    return 0;
}
