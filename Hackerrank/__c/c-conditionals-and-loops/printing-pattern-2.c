#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
      
    int row_count = (2*n) - 1;
    int col_count = n;
    int i,j,k,l;
    int flag=0;
    for(i=0;i<col_count;i++)
    {
        flag = 0;
        for(k=n;k>=(n-i);k--)
            printf("%d ",k);
        
        if(k!=0)
        k++;
        else
        k+=2;
        for(l=0;l<(((row_count)-(2*i + 1)))-1; l++)                
        {flag = 1;
         printf("%d ",k);
        }
        
        for(;k<=n;k++)
            printf("%d ",(k));
    
        printf("\n");
    }
    
    k=2;
    for(i=0;i<col_count-1;i++)
    {
        for(j=n;j>=k;j--)
        {
            printf("%d ",j);
        }
        j++;
        k++;
        for(l=0;l<((2*i)+1);l++)
        {
            printf("%d ",j);
        }
        for(;j<=n;j++)
        {
            printf("%d ",j);
        }
        printf("\n");
    }
    
    return 0;
}


