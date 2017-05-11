# css-cs-fixer

This tool intensd to find unused css elemenst. It parses css files and then check in the webroot folder if the class is actually used, like a css codebase recursive grep.



To compile use : gcc -Wall -o css-cs-fixer util.c search.c main.c argp.c

Requires dirent and argp
