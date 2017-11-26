#include "headers.h"

char ** parse_args( char * line ){

    char ** pointers = malloc (1000);

    int i = 0;

    char * entry = malloc(100);

    while ((entry = strsep(&line, " "))){
        pointers[i] = entry;
        i++;
        //printf("pointer %d: %s\n", i, entry);
    }
    pointers[i] = NULL;
    return pointers;

}

void execute(char ** args) {
  int status;
  if (!strcmp(args[0], "exit")) {//if exit command is called
    exit(0);
  }
  if (!strcmp(args[0], "cd")) {//if cd is called
    char nwd[512];
    getcwd(nwd, sizeof(nwd));
    strcat(nwd, "/");
    strcat(nwd, args[1]);
    printf("Changing to: %s\n", nwd);
    chdir(args[1]);
  }
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
  while (1) {//terminal keeps running
    char * userin = malloc(100);
    fgets(userin, 1000, stdin);
    strtok(userin, "\n"); //remove newline
    char ** args =  parse_args(userin);
    execute(args);
  }
  return 0;
}
