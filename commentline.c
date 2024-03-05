#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	printf("enter :");
	gets(str);
    if(str[0]=='/'&&(str[1]=='/'||str[1]=='*')){
		printf("\ncomment line");
	}else{
		printf("\nnot a comment line");
	}
}
