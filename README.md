# Shell Project
## by Jerome Freudenberg, Max Chan
### Period 4 Systems

## Features:

* Forks and executes commands
* Parses multiple commands on one line using semicolon
* Ignores whitespace between commands, semicolons, and |'s
* Redirects using < and >
* Uses pipes to pass information between commands
* Prints a command prompt when expecting user input

## Attempted Features:

* Error handling (e.g. file open didn't work or putting two semicolons next to each other)
* Added command prompt but it still displays .local as part of hostname and gets messed up after using a pipe
* Trim function to remove unnecessary whitespace, but it only handles leading and trailing whitespace, not whitespace between command and arguments


## Bugs:

* Putting two semicolons next to each other will break the parser, but doesn't throw an error
* Pressing ctrl + d makes it go wack and print the prompt a gajillion times before seg faulting.
* Pipes skew the prompts so that it prints with stdout instead of when taking input
* Cannot put whitespace between command and arguments
* Cannot use > then < in the same command, it will just create a file with the < symbol in it.
* Our redirection does things the shell doesn't (i.e. redirecting from file into wc).  Don't know if this is a bug or a 'feature'
* To exit the cat command, you need to hit end of file character twice, while in the regular shell it's only once
* After catting a file, you have to hit a newline to return to the command prompt
* You can only use one pipe
* Not guaranteed to grow hair
* Winged unicorns not promised, fast and magical transit not possible in NYC

***

## Files & Function Headers:

shell.c

### parse_args  
`char ** parse_args( char * line );`  
Input: char * line  
Returns: char ** array of command and arguments  
Used to turn a user input line into something you could feed into an execvp function  

### execute  
`void execute(char * line);`  
Input: char * line  
Returns: void  
Handles redirection, then forks and executes a single command in child process.

### execute_all  
`void execute_all(char * line);`  
Input: char * line  
Returns: void  
Runs execute multiple times, used to deal with command lines with semicolons  

### trim  
`char * trim(char * raw);`  
Input: char * raw  
Returns: char * new  
Takes a string array and removes leading and trailing whitespace

### stdout_to_file  
`void stdout_to_file(char * line);`  
Input: char * line  
Returns: void  
Used to redirect stdout to a file  

### file_to_stdin  
`void file_to_stdin(char * line);`  
Input: char * line  
Returns: void  
Used to redirect file to stdin  

### last_cwd
char * last_cwd(char cwd[])
Input: char array of current path
Returns: char array to current directory name
Used to display directory part of command prompt

### pipes
void pipes (char * line)
Input: line with a pipe in it
Returns: void
Used to run commands that have a pipe in them
