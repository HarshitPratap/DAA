#include<stdio.h>
#include<stdlib.h>

void cmm(int [][10],int [][10],int [],int);
void ops(int [][10],int,int);
void display(int [][10],int);
int main(int argc, char const *argv[])
{
    int m[10][10] = {0},s[10][10] = {0};
    int p[10] = {0};
    int i,n;
    printf("Enter the no. of matrices:- ");
    scanf("%d",&n);
    printf("Enter the diamension of matrices:- ");
    for (i = 0; i <= n; i++)
    {
        scanf("%d",&p[i]);
    }
    cmm(m,s,p,n);
    printf("\nOptimal solution:- \n");
    display(m,n);
    printf("\nOptimal parenthization:- \n");
    ops(s,1,n);
    return 0;
}

void cmm(int m[10][10],int s[10][10],int p[10],int n){
    int i,j,k,q,l;
    for (i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }
    for ( l = 2; l <= n; l++)
    {
        for ( i = 1; i <= n-l+1; i++)
        { 
            j = i + l - 1;
            m[i][j] = 99999;
            for ( k = i; k <= j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + (p[i-1]*p[k]*p[j]);
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }   
            }
        }  
    }
    printf("\nThe maximum no of scalar multiplication are:- %d",m[1][n]);
}

void ops(int s[10][10],int i,int j){
    if (i == j)
    {
        printf(" A%d ",i);
        return ;
    }else{
        printf("(");
        ops(s,i,s[i][j]);
        ops(s,s[i][j] +1 ,j);
        printf(")");
    }
    return ;
}
void display(int s[10][10],int n){
    int i,j;
    for ( i = 1; i <= n; i++)
    {
        for ( j = 0; j <= n; j++)
        {
            printf("%d ",s[i][j]);
        }
        printf("\n");
    }
}
