#include<stdio.h>
#include<stdlib.h>
#define MAX 10
void floyd(int);
int min(int,int);
int w[MAX][MAX],d[MAX][MAX][MAX];
int main()
{
    int i,j,v,k;
    printf("Enter the no. of nodes:- ");
    scanf("%d",&v);
    printf("Enter weight matrix:- ");
    for (i = 1; i <= v; i++)
    {
        for ( j = 1; j <= v; j++)
        {
            printf("Enter weight of %d to %d:- ",i,j);
            scanf("%d",&w[i][j]);
        }
    }
    floyd(v);
    return 0;
}
int min(int a,int b){
    return a>=b?b:a;
}
void floyd(int v){
    int k,i,j;
    k = 0;
    for (i = 1; i <= v; i++)
    {
        for (j = 1; j <= v; j++)
        {
            d[k][i][j] = w[i][j];
        }
    }
    for (k = 1; k <= v; k++)
    {
        for (i = 1; i <= v; i++)
        {
            for ( j = 1; j <= v; j++)
            {
                d[k][i][j] = min(d[k-1][i][j],(d[k-1][i][k] + d[k-1][k][j]));
            }
        } 
    }
    for (k = 0; k <= v; k++)
    {
        printf("%dth matrix:- \n",k);
        for (i = 1; i <= v; i++)
        {
            for ( j = 1; j <= v; j++)
            {
                printf("\t%d ",d[k][i][j]);
            }
            printf("\n");
        }
    }
}
