#include "ccf.h"
#include "argp.h"
#include "search.h"


int main(int argc, char *argv[])
{

    struct arguments arguments;
    arguments.silent = 0;
    arguments.verbose = 0;
    arguments.output_file = "-";
    argp_parse (&argp, argc, argv, 0, 0, &arguments);

    char *files[1000];
    int index = 0;

    css_file_search(arguments.args[0], files, &index);
   
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
    return 0;
}
