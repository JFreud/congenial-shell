#include "headers.h"

char ** parse_args( char * line ){

    char ** pointers = malloc (1000);

    int i = 0;

    char * entry = malloc(100);
    while (entry = strsep(&line, " "), entry != NULL){

	pointers[i] = entry;
        i++;
	//printf("pointer %d: %s\n", i, entry);

    }

    pointers[i] = NULL;

    //printf("[%s]\n", strsep( &line, " " ));
    //printf("[%s]\n", line);

	free(entry);
    return pointers;

}

int main(){

    char line[100] = "ls -a -l";

    char * p = line;

    char ** args = parse_args(p);

    /*
    printf("args 1: %s\n", args[0]);
    printf("args 2: %s\n", args[1]);
    printf("args 3: %s\n", args[2]);
    printf("args 4: %s\n", args[3]);
    */

    //printf("args: %s, %s", args[0], args[1]);

    execvp(args[0], args);
    return 0;

}
