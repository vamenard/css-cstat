# css-cs-fixer

This tool intends to find unused css elements. It parses css files and then check in the webroot folder if the class is actually used, like a css codebase recursive grep. Requires dirent and argp.


To compile use : gcc -Wall -o css-cs-fixer util.c search.c argp.c main.c -Wno-unused-variable


Usage: css-cs-fixer [OPTION...] path

