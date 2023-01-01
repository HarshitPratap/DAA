#include<stdio.h>
#include<stdlib.h>
void swap(float *a,float *b){
    float t = *a;
    *a = *b;
    *b = t;
}
int main(int argc, char const *argv[])
{
    int n,i,j;
    float m[10][3],x[10];
    float wgt,max,v;
    printf("Enter no of items:- ");
    scanf("%d",&n);
    printf("Enter Weight and Values of items:- ");
    for ( i = 0; i < n; i++)
    {
        printf("Enter weight and value of %dth item:- ",i+1);
        scanf("%f%f",&m[i][0],&m[i][1]);
    }
    printf("Enter capacity of the Knapsack:- ");
    scanf("%f",&wgt);
    
    //calculating value per unit
    for (i = 0; i < n; i++)
    {
        m[i][2] = m[i][1]/m[i][0];
    }
    
    //arranging in desending order on value per unit
    for (i = 0; i < n - 1; i++)
    {
        for ( j = 0; j < n - i - 1; j++)
        {
            if (m[j][2] < m[j+1][2])
            {
                swap(&m[j][0],&m[j+1][0]);
                swap(&m[j][1],&m[j+1][1]);
                swap(&m[j][2],&m[j+1][2]);
            }
        }
    }
    //actual logic
    for ( i = 0; i < n; i++)
    {
        x[i] = 0;
    }
    v = wgt;
    for ( i = 0; i < n; i++)
    {
        if (m[i][0] > v) break;
        x[i] = m[i][0];
        v -= m[i][0];
    }
    if(i < n)
        x[i] = v / m[i][0];
    //solution vector
    for ( i = 0; i < n; i++)
    {
        printf("%.2f, ",x[i]);
    }
    max = 0;
    for ( i = 0; i < n; i++)
    {
        max += (m[i][2] * x[i]);
    }
    printf("\nMaximum profit earned:- %.2f",max);
    return 0;
}
