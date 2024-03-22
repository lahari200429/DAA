#include<stdio.h>
void copystring(char *source,char *destination){
	if(*source == '\0'){
		*destination ='\0';
	}
	else{
		*destination = *source;
		copystring(source +1,destination +1);
	}
}
int main(){
	char source []="hello world";
	char destination[50];
	copystring(source,destination);
	printf("source:%s",source);
	printf("destination:%s",destination);
	
}
