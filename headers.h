#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <errno.h>


char ** parse_args( char * line );
void execute(char * line);
void execute_all(char * line);
char * trim(char * raw);
void stdout_to_file(char * line);
void file_to_stdin(char * line);
