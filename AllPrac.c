#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printArray(int *data,int size){
    int i;
    for ( i = 0; i < size; i++)
    {
        printf("%d ",data[i]);
    }
}

void adjust(int *d,int l,int h){
	int i,ele;
	i = 2 * l;
	ele = d[l];
	while(i <= h){
		if(i<h && d[i] < d[i+1])
			i++;
		if(ele >= d[i])
			break;
		d[i/2] = d[i];
		i = 2 * i;
	}
	d[i/2] = ele;
}
void heapify(int *d,int s){
	int i;
	for(i = s/2;i>=0;i--)
		adjust(d,i,s);
}
void heapSort(int *d,int s){
	int i;
	heapify(d,s);
	for(i = s;i>=1;i--){
		swap(&d[0],&d[i]);
		adjust(d,0,i-1);
	}
}

int partion(int *d,int l,int h){
	int i,j,p;
	p = d[h];
	i = l-1;
	for(j = l;j<h;j++){
		if(d[j] <= p){
			i++;
			swap(&d[i],&d[j]);
		}
	}
	swap(&d[i+1],&d[h]);
	return i+1;
}

void quickSort(int *d,int l, int h){
	int p;
	if(l<h){
		p = partion(d,l,h);
		quickSort(d,l,p-1);
		quickSort(d,p+1,h);
	}
}

void iSort(int *d,int s){
	int i,v,j;
	for(i = 1;i<s;i++){
		j = i-1;
		v = d[i];
		while(j>=0 && d[j] > v){
			d[j+1] = d[j];
			j--;
		}
		d[j+1] = v;
	}
}

void merge(int *d,int l,int m,int h){
	int c[10];
	int i,j,k,p;
	i = l;
	j = m+1;
	k = l;
	while((i <= m) && (j <= h)){
		if(d[i] <= d[j])
			c[k++] = d[i++];
		else
			c[k++] = d[j++];
	}
	for(p=i;p<=m;p++){
		c[k++] = d[p];
	}
	for(p=j;p<=h;p++){
		c[k++] = d[p];
	}
	for(p = l;p<=h;p++){
		d[p] = c[p];
	}
}
void mergeSort(int *d,int l,int h){
	int m;
	if(l<h){
		m = (l+h)/2;
		mergeSort(d,l,m);
		mergeSort(d,m+1,h);
		merge(d,l,m,h);
	}
}
int main(){
	int n = 10;
    int data[10] = {89,78,0,25,32,12,65,90,45,65};
    //heapSort(data,n-1);
    //quickSort(data,0,n-1);
    //iSort(data,n);
    mergeSort(data,0,n-1);
    printArray(data,n);
	return 0;
}
