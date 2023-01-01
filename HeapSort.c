#include<stdio.h>

void adjust(int,int);
void heapify(int);
int arr[25];
int main(){
    int temp,i,n;
    printf("Enter number of elements in array:- ");
    scanf("%d",&n);
    printf("Enter elements of array:- ");
    for (i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    heapify(n-1);
    for (i = n-1; i >= 1; i--)
    {
       temp = arr[0];
       arr[0] = arr[i];
       arr[i] = temp;
       adjust(0,i-1); 
    }
    printf("\nSorted array:- ");
    for ( i = 0; i < n; i++)
    {
        printf("%d, ",arr[i]);
    }
    return 0;
}

void heapify(int n){
    int j;
    for (j = n/2; j >= 0; j--)
    {
        adjust(j,n);
    }
}

void adjust(int i,int n){
    int j,ele;
    j = 2*i;
    ele = arr[i];
    while (j<=n)
    {
        if(j<n && arr[j] < arr[j+1])
            j=j+1;
        if(ele >= arr[j]) 
			break;
		else
        	arr[j/2] = arr[j];	
        j = 2*j;    
    }
    arr[j/2] = ele;
}
