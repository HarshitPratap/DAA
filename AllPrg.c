#include<stdio.h>
#define MAX 100
int lSearch(int *data,int key,int size){
    int i;
    for ( i = 0; i < size; i++)
    {
        if (data[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int bSearch(int *data,int key,int low,int high){
    int mid = (low + high)/2;
    if (data[mid] == key)
    {
        return mid;
    }else if(key < data[mid]){
        bSearch(data,key,low,mid-1);
    }else{
        bSearch(data,key,mid+1,high);
    }
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partion(int *data,int low,int high){
    int pivot = data[high];
    int i = low-1;
    int j;
    for ( j = low; j < high; j++)
    {
        if (data[j] <= pivot)
        {
            i++;
            swap(&data[i],&data[j]);
        }
    }
    swap(&data[i+1],&data[j]);
    return i+1;
}

void quickSort(int *data,int low,int high){
    if (low < high)
    {
        int p = partion(data,low,high);
        quickSort(data,low,p-1);
        quickSort(data,p+1,high);
    }
}

void insertionSort(int *data,int size){
    int v;
    int i,j;
    for ( i = 1; i < size; i++)
    {
       v = data[i];
       j = i-1;
       while (data[j] > v && j >= 0)
       {
            data[j+1] = data[j];
            j--;
       }
        data[j+1] = v;
    }
}

void printArray(int *data,int size){
    int i;
    for ( i = 0; i < size; i++)
    {
        printf("%d ",data[i]);
    }
}
void merge(int *data,int low,int mid,int high){
    int arr[10];
    int i,j,k,p;
    i = low; k = low;
    j = mid+1;
    while ((i <= mid) && (j <= high))
    {
        if (data[i] <= data[j])
        {
            arr[k++] = data[i++];
        }else{
            arr[k++] = data[j++];
        }
    }
    for ( p = j; p <= high; p++)
    {
        arr[k++] = data[p];
    }
    for ( p = i; p <= mid; p++)
    {
        arr[k++] = data[p];
    }
    for ( p = low; p <= high; p++)
    {
        data[p] = arr[p];
    }
}

void mergeSort(int *data,int low,int high){
    int mid;
    if (low < high)
    {
        mid = (low + high)/2;
        mergeSort(data,low,mid);
        mergeSort(data,mid+1,high);
        merge(data,low,mid,high);
    }
}
void adjust(int *data,int low,int high){
    int ele,i;
    ele = data[low];
    i = 2*low;
    while (i <= high)
    {
        if (i < high && data[i] < data[i+1])
            i++;
        if (ele >= data[i])
            break;
        data[i/2] = data[i];
        i = 2 * i;      
    }
    data[i/2] = ele;
}
void heapify(int *data,int size){
    int i;
    for (i = size/2; i >= 0; i--)
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
int main()
{
    int n,i;
    int data[MAX];
    printf("Enter the no. of elements in array:- ");
    scanf("%d",&n);
    printf("Enter elements of array:- ");
    for(i = 0; i < n;i++)
    	scanf("%d",&data[i]);
//    i = lSearch(data,79,n);
//    printf("Element find at:- %d",i);
    printf("\nSorted array:- ");
    //quickSort(data,0,n-1);
    //insertionSort(data,n);
    //mergeSort(data,0,n-1);
    heapSort(data,n-1);
    printArray(data,n);
    //i = bSearch(data,12,0,n-1);
    //printf("\nElement find at:- %d",i);
    return 0;
}

