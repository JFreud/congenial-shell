#include "headers.h"

char ** parse_args( char * line ){

    char ** pointers = malloc (1000);

    int i = 0;

    char * entry = malloc(100);

    while ((entry = strsep(&line, " "))){

        //if (entry[0] == '-') entry++;
        pointers[i] = entry;
        //printf("entry: %s\n", entry);
        printf("%d\n", i);
        i++;
        printf("pointer %d: %s\n", i, entry);

    }
    pointers[i] = NULL;

    //printf("[%s]\n", strsep( &line, " " ));
    //printf("[%s]\n", line);

    //free(entry);

    printf("running: %s\n", pointers[0]);
    printf("end: %s\n", pointers[i]);
    //execvp(pointers[0], pointers);


    return pointers;

}

void execute(char ** args) {
  int status;
  if (strcmp(args[0], "cd") == 0){
    //insert edge case change directory stuff
  }
  else {
    if (fork()) {//parent
      wait(&status);
    }
    else {//child that executes command
      execvp(args[0], args);
      exit(0);
    }
  }
}

int main(){

  char * userin = malloc(100);
  fgets(userin, 1000, stdin);
  strtok(userin, "\n"); //remove newline


  printf("size of userin: %lu\n", sizeof(userin));

  //printf("size of reading: %lu\n", sizeof(reading));

  printf("User in: %s\n", userin);

  char ** args =  parse_args(userin);

  //execvp(args[0], args);
  printf("args[0] = %s\n", args[0]);
  printf("args[1] = %s\n", args[1]);
  printf("args[2] = %s\n", args[2]);


  // printf("%d\n", strcmp(args[0], "ls"));
  // printf("%d\n", strcmp(args[1], "-a"));
  // printf("%d\n", strcmp(args[2], "-l\n"));
  //
  // args[0] = "ls";
  // args[1] = "-a";
  // args[2] = "-l";
  execvp(args[0], args);


  //execute(args);

  return 0;
}
