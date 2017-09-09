# css-cs-fixer

This tool intends to find unused css elements. It parses css files and then check in the webroot folder if the class is actually used, like a css codebase recursive grep. No file will be modified, it is only a code analysis tool. It currently only looks for root css classes. Requires dirent and argp.

To compile use : gcc -Wall -o css-cs-fixer util.c search.c argp.c grep.c css_entity.c main.c 


Usage: css-cs-fixer [OPTION...] path


Output example :

$ ./css-cs-fixer /var/www

Cross referencing CSS classes with template files...
Class sf-reset - 4 occurences
Class sf-button - 1 occurences
Class sf-button-selected - 0 occurences
Class clear - 6 occurences
Class clear-fix:after - 0 occurences
Class clear-fix - 4 occurences
Class header - 92 occurences
Class header-logo - 1 occurences
Class search - 42 occurences
Class sf-minitoolbar - 1 occurences
Class sf-toolbarreset - 2 occurences
Class sf-toolbar-block - 4 occurences
Class sf-toolbar-block.sf-toolbar-status-green - 0 occurences
Class sf-toolbar-block.sf-toolbar-status-red - 0 occurences
Class sf-toolbar-block.sf-toolbar-status-yellow - 0 occurences
Class sf-toolbar-block-request - 0 occurences
Class sf-toolbar-status-red - 2 occurences
Class sf-toolbar-status-yellow - 1 occurences
Class sf-toolbar-block-config - 0 occurences
Class sf-toolbar-block:hover - 0 occurences
Class sf-toolbar-info-piece - 54 occurences
Class sf-toolbar-ajax-requests - 4 occurences
Class sf-ajax-request-url - 1 occurences
Class sf-ajax-request-duration - 1 occurences
Class sf-ajax-request-loading - 3 occurences
Class sf-toolbar-block-dump - 0 occurences
Class sf-toolbar-icon - 1 occurences
Class sf-toolbar-block-memory - 0 occurences
Class sf-toolbar-block-time - 0 occurences

