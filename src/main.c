#include "ccf.h"
#include "search.h"

int main(int argc, char *argv[])
{

    char *files[10];
    int index = 0;

    css_file_search("/var/www/", files, &index);
    printf("----%s", files[1]);
    return 0;
}
