#include<stdio.h>

int main(){
	int m[10][2];
	int v[10][10];
	int i,j,a,b,n,wgt,w,max;
	printf("Enter number of items:- ");
	scanf("%d",&n);
	printf("Enter capacity of kanpsack:- ");
	scanf("%d",&wgt);
	printf("Enter weight and value of items:- ");
	for(i = 0;i<n;i++){
		scanf("%d %d",&m[i][0],&m[i][1]);
	}
	for(i = 0;i<=n;i++){
		for(j =0;j<=wgt;j++){
			if(i == 0 && j >= 0)
				v[i][j] = 0;
			else if(i >= 0 && j == 0)
				v[i][j] = 0;
			else if( j - m[i-1][0] < 0)
				v[i][j] = v[i-1][j];
			else if( j - m[i-1][0] <= 0){
				a = v[i-1][j];
				b = m[i-1][j] + v[i-1][j-m[i-1][0]];
				if(a>b)
					v[i][j] = a;
				else
					v[i][j] = b;
			}	
		}
	}
	max = 0;
	w = 0;
	i = n;
	j = wgt;
	printf("\nItems\tWeight\tValue");
	while((wgt - w) > 0){
		if(v[i][j] != v[i-1][j]){
			printf("\n%d\t%d\t%d",i,m[i-1][0],m[i-1][1]);
			max+=m[i-1][1];
			j = wgt - w;
			w+=m[i-1][0];
		}
		i--;
		if(i<1)
			break;
	}
	printf("\nMaximum profit earned:- %d",max);
	return 1;
}
