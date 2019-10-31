#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i,temp;
    scanf("%d", &num);
    int arr[num];
    for(i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }
        
    for(i=0;  ;i++)
    {
        if(i>=num-1-i)
            break;
        temp = arr[i];
        arr[i] = arr[num-i-1];
        arr[num-1-i] = temp;
    }
    for(i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }
    

}
