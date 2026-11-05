# css-cstat

This tool intends to find unused css elements. It parses css files and then check in the webroot folder if the class is actually used, a css codebase recursive grep. No file will be modified, it is only a code analysis tool. It currently only looks for root css classes. Requires dirent and argp.

To compile use : gcc -Wall -o css-cstat util.c search.c argp.c grep.c css_entity.c main.c 


## Usage: 

```
css-cstat [OPTION...] path

```

## Output example :

```
$ ./css-cstat /var/www
Cross referencing CSS classes with template files...
Class sf-reset - 4 occurences
Class sf-button - 1 occurences
Class sf-button-selected - 0 occurences

Class clear - 6 occurences
...
```

## Contributor

Vincent Menard <github@vcpu.com> 2017 - 2026


