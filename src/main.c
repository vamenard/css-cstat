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
    static char *root_classes[1024];
    static char *tpl[255];


    int index = 0, cindex = 0, tindex = 0;
    int c1;

    file_search(arguments.args[0], files, &index, tpl, &tindex);

    if (arguments.verbose) { 
        printf ("\nPath = %s\nOUTPUT_FILE = %s\n"
            "VERBOSE = %s\nSILENT = %s\n",
            arguments.args[0],
            arguments.output_file,
            arguments.verbose ? "yes" : "no",
            arguments.silent ? "yes" : "no");

        printf("%s\n", "\nCSS files found within provided path :");
        for (c1 = 0; c1 < index; c1++)
            printf("%s\n", files[c1]);
    }

    for (c1 = 0; c1 < index; c1++) {
        parse_root_entity( files[c1], root_classes, &cindex, arguments.verbose );
    }

    if (arguments.verbose) {
        printf("\n");
        for (c1 = 0; c1 < cindex; c1++)
            printf("Root class found \"%s\"\n", root_classes[c1]);
        printf("\nThe following template files were found within the provided path:\n");
        for (c1 = 0; c1 < tindex; c1++)
            printf("%s\n", tpl[c1]);

    }

    printf("\nCross referencing CSS classes with template files...\n");
    build_css_xref( tpl, &tindex, root_classes, &cindex, arguments.verbose);
 
    return 0;
}
