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

void execute(char * command) {
  if (strstr(command, ">") != NULL) {//if uses redirect
    stdout_to_file(command);
  }
  if (strstr(command, "<") != NULL) {
    file_to_stdin(command);
  }
  char ** args = parse_args(command);
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

void stdout_to_file(char * line) {
  char * command = strsep(&line, ">");
  char * file = line;
  command = trim(command); //input
  file = trim(file); //output
  printf("command: %s\n", command);
  printf("file: %s\n", file);
  int fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  printf("fd: %d\n", fd);
  //printf("Errno: %s\n", strerror(errno));
  int fout = fileno(stdout);
  int newout = dup(fout);//file no of stdout
  dup2(fd, fout);
  execute(command);
  dup2(newout, fout);
  close(newout);
}

void file_to_stdin(char * line) {
  char * file = strsep(&line, "<");
  char * command = line;
  command = trim(command);
  file = trim(file);


  int fd = open(file, O_RDONLY);
  int newin = dup(0);//file no of stdin
  dup2(fd, 0);
  execute(command);
  dup2(newin, 0);
  close(newin);
}


void execute_all(char * line){
    int i = 0;
    char * command = malloc(100);

    while ((command = strsep(&line, ";"))){
        //printf("command: %s\n", command);
        command = trim(command);
        execute(command);
        i++;

    }
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
    execute_all(userin);
  }
  return 0;
}
