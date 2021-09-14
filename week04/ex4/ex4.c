#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define MAX_BUF 256
#define MAX_ARGS 10

void split(char str[], char *args[]){
		for(int i=0 ; i<MAX_BUF ; i++)
			if(str[i] == '\n')
				str[i] = '\0';
		char *token = strtok(str, " ");
		int argc=0;
		while(token != NULL){
			args[argc] = token;
      argc++;
			token = strtok(NULL, " ");
		}
		args[argc]=NULL;
}


int main()
{
	char str[MAX_BUF];
	char *args[MAX_ARGS];
	while(1){
		fgets(str, MAX_BUF, stdin);
    split(str, args);
		int x = fork();
		if( x == 0 )
				execvp(args[0], args);
	}
	return 0;
}
