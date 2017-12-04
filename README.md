# Shell Project
## by Jerome Freudenberg, Max Chan

## Features:

* Forks and executes commands
* Parses multople commands on one line using semicolon
* Ignores whitespace between commands, arguments, semicolons, and |'s
* Redirects using >, <
* Uses pipes to pass information between commands
* Not guaranteed to grow hair
* Winged unicorns not promised, fast and magical transit not possible in NYC

## Attempted Features:

* Tried to list current directory as prompt.  Kind of works, but just lists address:directory instead of just directory

## Bugs:

* Putting two semicolons next to each other will break the parser (I included this cuz Mr. DW had it on his example, but the regular shell can't deal with it either)
* Cannot use < and > in the same command (again, shell doesn't do this either but thought we should mention it)
* Our redirection works too well, can do things the shell can't (i.e. redirecting from wc into a file).  Don't know if this is a bug or a 'feature'
* To exit the cat command, you need to hit end of file character twice, while in the regular shell it's only once

***

## Files & Function Headers:

### parse_args  
`char ** parse_args( char * line );`  
Input: char * line  
Returns: char ** array of command and arguments  
Used to turn a user input line into something you could feed into an execvp function  

### execute  
`void execute(char * line);`  
Input: char * line  
Returns: void  
Decides which function to use to deal with the user inputed line  

### execute_all  
`void execute_all(char * line);`  
Input: char * line  
Returns: void  
Runs execute multiple times, used to deal with command lines with semicolons  

### trim  
`char * trim(char * raw);`  
Input: char * raw  
Returns: char * new  
Takes a string array and removes whitespace from beginning and end  

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