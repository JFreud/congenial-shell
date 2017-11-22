#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

void execute( char * line ){

    char ** pointers = malloc (1000);

    int i = 0;

    char * entry = malloc(100);

    while (entry = strsep(&line, " "), entry != NULL){
        
	pointers[i] = entry;
        i++;
	printf("pointer %d: %s\n", i, entry);	

    }

    pointers[i] = NULL;

    //printf("[%s]\n", strsep( &line, " " ));
    //printf("[%s]\n", line);

    //free(entry);

    printf("running: %s\n", pointers[0]);
    printf("end: %s\n", pointers[1]);
    execvp(pointers[0], pointers);
    
    //return pointers;

}

int main(){

  char * userin = malloc(1000);
  
  //prinf("$");
  //scanf("%s", userin);

  fgets(userin, 100, stdin);
  
  printf("User in: %s\n", userin);
  
  execute(userin);
  
  return 0;
}
