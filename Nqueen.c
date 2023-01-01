#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int place(int k,int i,int *x){
    int j;
    for (j = 1; j <= k-1; j++)
    {
        if (x[j] == i || abs(j-k) == abs(x[j]-i))
        {
            return 0;
        }
    }
    return 1;
}
void NQueen(int k,int n,int *x){
    int i,j;
    for (i = 1; i <= n; i++)
    {
        if (place(k,i,x))
        {
            x[k] = i;
            if (k == n)
            {
                printf("Solutions Matrix is:-\n");
                for (i = 1; i <= n; i++)
                {
                    for ( j = 0; j <= n; j++)
                    {
                        if (x[i] == j)
                        {
                            printf(" Q ");
                        }else{
                            printf(" 0 ");
                        }
                    }
                    printf("\n");
                }
            }else{
                NQueen(k+1,n,x);
            }
            
        }
    }
}

int main(int argc, char const *argv[])
{
    int x[10],N;
    printf("Enter the number of row:- ");
    scanf("%d",&N);
    NQueen(1,N,x);
    return 0;
}
