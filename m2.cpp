#include<stdio.h>
int fib(int n){
	if(n==0){
		return 0;
	}
	else if(n==1){
		return 1;
	}
	else{
		return(fib(n-1)+fib(n-2));
	}
}
int main(){
	int i,n,sum=0;
	printf("enter no.of elements:");
	scanf("%d",&n);
	printf("fibonacci series:");
	for(i=0;i<n;i++){
		printf("%d \t",fib(i));
		if(i%2 == 0){
			sum+=fib(i);
		}
	}
	printf("\neven sum of fibonacci is :%d",sum);
}
