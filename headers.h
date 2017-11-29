#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <ctype.h>


char ** parse_args( char * line );
void execute(char ** args);
char * trim(char * raw);
