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

void execute_all(char * line){
    int i = 0;

    char * command = malloc(100);

    while ((command = strsep(&line, ";"))){
        
        char ** args = parse_args(command);
        execute(args);
        i++;
        
    }
}

int main(){
  while (1) {//terminal keeps running
    char * userin = malloc(500);
    fgets(userin, 500, stdin);
    strtok(userin, "\n"); //remove newline
    execute_all(userin);
  }
  return 0;
}
