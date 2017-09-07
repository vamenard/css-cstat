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

    static char *files[255];
    static char *root_classes[20000];
    static char *tpl[255];

    int index = 0;
    int cindex = 0;
    int tindex = 0;

    file_search(arguments.args[0], files, &index, tpl, &tindex);

    if (arguments.verbose) { 
        printf ("\nPath = %s\nOUTPUT_FILE = %s\n"
            "VERBOSE = %s\nSILENT = %s\n",
            arguments.args[0],
            arguments.output_file,
            arguments.verbose ? "yes" : "no",
            arguments.silent ? "yes" : "no");

        printf("%s\n", "\nCSS files found within provided path :");
        int c;
        for (c = 0; c < index; c++)
            printf("%s\n", files[c]);
    }
    // find root css classes
    int c;
    printf("\n");

    for (c = 0; c < index; c++)
        parse_root_entity( files[c], &root_classes, &cindex );

    if (arguments.verbose) {
        for (c = 0; c < cindex; c++)
            printf("Root class found \"%s\"\n", root_classes[c]);
    }

    printf("\nThe following template files were found within the provided path:\n");
    for (c = 0; c < tindex; c++) {
        printf("%s\n", tpl[c]);
    }

    printf("\nCross referencing CSS classes with template files...\n");
    int c2;
 
    for (c = 0; c < cindex; c++) {
        for (c2 = 0; c2 < tindex; c2++) {
            grep_single_file( tpl[c2], root_classes[c], arguments.verbose);
        }
    }

    return 0;
}
