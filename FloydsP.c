#include<stdio.h>
#define MAX 20
int d[MAX][MAX][MAX],w[MAX][MAX];
void floyd(int );
int main(){
    int v,i,j;
    printf("\nEnter no. of nodes:- ");
    scanf("%d",&v);
    for ( i = 1; i <= v; i++)
    {
        for (j = 1; j <= v; j++)
        {
            printf("\nEnter cost from %d to %d",i+1,j+1);
            scanf("%d",&w[i][j]);
        } 
    }
    floyd(v);
    return 0;
}
void floyd(int v){
    int i,j,k=0;
    for (i = 1; i <= v; i++)
    {
        for (j = 1; j <= v; j++)
        {
            /* code */
        }
        
    }
    
}