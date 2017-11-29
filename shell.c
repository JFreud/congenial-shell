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
        //printf("command: %s\n", command);
        command = trim(command);
        char ** args = parse_args(command);
        execute(args);
        i++;

    }
}

void piping(char * line){

  char ** pointers = malloc (1000);
    int i = 0;
    char * entry = malloc(100);
    while ((entry = strsep(&line, "|"))){
      pointers[i] = trim(entry);
        i++;
    }
    pointers[i] = NULL;
  
    FILE *fp = popen(pointers[0], "r");

    char * info = malloc(99999 + 1);
    fgets(info, sizeof(info), fp);
    
    char ** args = malloc(100);
    args[1] = info;
    args[2] = NULL;

    execvp(pointers[1], args);
    pclose(fp);

}

char * trim(char * raw){
  while (isspace(*raw)) {
    raw++;
  }

  char * end = raw + strlen(raw);
  while (isspace(*(end - 1))) {
    end--;
  }
  *end = 0;
  return raw;
}

int main(){
  while (1) {//terminal keeps running
    char * userin = malloc(500);
    fgets(userin, 500, stdin);
    strtok(userin, "\n"); //remove newline
    userin = trim(userin);
    //execute_all(userin);
    piping(userin);
  }
  return 0;
}
