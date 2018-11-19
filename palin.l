%{
	#include <stdio.h>
	#include <string.h>
	char*s;	
	int isPalindrome(char* str);
%}

%%
[a-zA-Z0-9]+ {isPalindrome(yytext);}
. ;
%%

int isPalindrome(char* str){
	int l=strlen(str);
	int i=0,j=l-1;

	while(i<j){
		if(str[i]!=str[j]){
			printf("Its not a palindrome\n");
			return 0;
		}
		i++;
		j--;
	}

	printf("Its a palindrome\n");
	return 1;
}

int main(void){
	yylex();
	return 0;
}
