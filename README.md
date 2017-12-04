# Shell Project
## by Jerome Freudenberg, Max Chan

## Features:

-Forks and executes commands
-Parses multople commands on one line using semicolon
*Ignores whitespace between commands, arguments, semicolons, and |'s
*Redirects using >, <
*Uses pipes to pass information between commands
*Not guaranteed to grow hair
*Winged unicorns not promised, fast and magical transit not possible in NYC

## Attempted Features:

*Tried to list current directory as prompt.  Kind of works, but just lists address:directory instead of just directory

## Bugs:

*Putting two semicolons next to each other will break the parser (I included this cuz Mr. DW had it on his example, but the regular shell can't deal with it either)
*Cannot use < and > in the same command (again, shell doesn't do this either but thought we should mention it)
*Our redirection works too well, can do things the shell can't (i.e. redirecting from wc into a file).  Don't know if this is a bug or a 'feature'
*To exit the cat command, you need to hit end of file character twice, while in the regular shell it's only once

***

## Files & Function Headers:

