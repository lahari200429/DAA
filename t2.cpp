#include<stdio.h>
int main(){
	int i,num,sum=0;
	printf("enter a number: ");
	scanf("%d",&num);
	for(i=0;i<num/2;i++){
		sum+=i;
	}
	if(sum==num&num>0){
		printf("it is a perfect number");
	}
	else{
		printf("%d is not a perfect number");
	}
}
