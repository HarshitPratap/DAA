#include<stdio.h>

void mergeSort(int[],int,int);
void merge(int[],int,int,int);
int main(){
    int n,i,j;
    int arr[30];
    printf("Enter the no. of element:- ");
    scanf("%d",&n);
    printf("\nEnter the elements array:- ");
    for( i = 0; i < n; i++)
    {
       scanf("%d",&arr[i]); 
    }
    mergeSort(arr,0,n-1);
    printf("\nSorted array:- ");
    for( i = 0; i < n; i++)
    {
       printf("%d, ",arr[i]); 
    }
    return 0;
}
void merge(int arr[],int l,int m,int h){
   int c[30];
   int i,j,k,p;
   i = l; j = m+1;
   k = l;
   while ( (i <= m) && (j <= h))
   {
      if ((arr[i] <= arr[j]))
      {
         c[k] = arr[i];
         i++;
      }else{
         c[k] = arr[j];
         j++;
      }
      k++;
   }
   if (i > m)
   {
      for ( p = j; p <= h; p++)
      {
         c[k++] = arr[p];
      }
   }else
   {
      for ( p = i; p <= m; p++)
      {
         c[k++] = arr[p];
      }
   }

   for ( p = l; p <= h; p++)
   {
      arr[p] = c[p];
   }
}
void mergeSort(int arr[],int l,int h){
   int m = 0;
   if (l<h)
   {
      m = (l+h)/2;
      mergeSort(arr,l,m);
      mergeSort(arr,m+1,h);
      merge(arr,l,m,h);
   }
}