#include<stdio.h>
void swap(int *a,int *b){
    int t = *a;
    *a = *b;
    *a = t;
}
void adjust(int *data,int low,int high){
    int ele = data[low];
    int j = 2 * low;
    while (j <= high)
    {
       if (j < high && data[j] < data[j+1])
            j++;
       if (data[j] <= ele)
            break;
        data[j/2] = data[j];
        j = 2 * j;
    }
    data[j/2] = ele;
}
void heapify(int *data,int size){
    int i;
    for ( i = size/2; i >= 0; i--)
    {
        adjust(data,i,size);
    }
}
void heapSort(int *data,int size){
    int i;
    heapify(data,size);
    for ( i = size; i >= 1; i--)
    {
        swap(&data[0],&data[i]);
        adjust(data,0,i-1);
    }  
}