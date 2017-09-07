#include "ccf.h"
#include "argp.h"
#include "search.h"
#include "grep.h"
#include "css_entity.h"

int main(int argc, char *argv[])
{

    struct arguments arguments;
    arguments.silent = 0;
    arguments.verbose = 0;
    arguments.output_file = "-";
    argp_parse (&argp, argc, argv, 0, 0, &arguments);

    char *files[10000];
    char *root_classes[10000];

    int index = 0;
    int cindex = 0;

    file_search(arguments.args[0], files, &index, ".css");
    
    if (arguments.verbose) { 
        printf ("path = %s\nOUTPUT_FILE = %s\n"
            "VERBOSE = %s\nSILENT = %s\n",
            arguments.args[0],
            arguments.output_file,
            arguments.verbose ? "yes" : "no",
            arguments.silent ? "yes" : "no");

        printf("%s\n", "CSS files found within provided path :");
        int c;
        for (c = 0; c < index; c++)
            printf("%s\n", files[c]);
    }
    // find root css classes
    int c;
    for (c = 0; c < index; c++)
        parse_root_entity( files[c], root_classes, &cindex );

    if (arguments.verbose) {

        for (c = 0; c < cindex; c++)
            printf("Root class found \"%s\"\n", root_classes[c]);
    }
    sleep(1);

    // now parse again for html files
    char *tpl[10000];
    int tindex = 0;
    file_search(arguments.args[0], tpl, &tindex, ".html");
    
    int c2;
    for (c2 = 0; c2 < tindex; c2++)
        printf("%s\n", tpl[c2]);


    grep_single_file( files[0], "bundle", arguments.verbose);

    return 0;
}
