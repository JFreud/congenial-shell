#include "headers.h"

char ** read_input( char * line ){

    char ** pointers = malloc (1000);

    int i = 0;

    char * entry = malloc(100);

    while (entry = strsep(&line, " -"), entry != NULL){

        pointers[i] = entry;
        i++;
        printf("pointer %d: %s\n", i, entry);

    }
    pointers[i] = NULL;

    //printf("[%s]\n", strsep( &line, " " ));
    //printf("[%s]\n", line);

    free(entry);

    printf("running: %s\n", pointers[0]);
    printf("end: %s\n", pointers[i]);
    //execvp(pointers[0], pointers);

    return pointers;

}

int main(){

  char * userin = malloc(100);

  fgets(userin, 1000, stdin);

  printf("size of userin: %lu\n", sizeof(userin));

  //printf("size of reading: %lu\n", sizeof(reading));

  printf("User in: %s\n", userin);

  char ** args =  read_input(userin);

  //execvp(args[0], args);
  printf("args[0] = %s\n", args[0]);
  printf("args[1] = %s\n", args[1]);
  printf("args[2] = %s\n", args[2]);

  execvp(args[0], args);

  return 0;
}
