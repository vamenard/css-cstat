#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <errno.h>
#include <dirent.h>
#include <limits.h>
#include <inttypes.h>
#include <stdint.h>

#include "util.h"

int parse_root_entity( char *path[], char *root_classes[], int *cindex ) {

    printf("Opening css file %s for analysis.\n", path);

    char fline[10000];

    char *newline;
    int i,count=0;
    FILE *fp;

    fp = fopen(path,"r");

    char *p;
    char *one_line_array[1000];

    int duplicate = 0;
    while (fgets(fline,100,fp)!=NULL) {
        count++;
        if (newline=strchr(fline,'\n'))
            *newline='\0';

        if ((strstr(fline, "." ) !=NULL ) && ( strstr(fline, "{" ) !=NULL )  ) {
            
            // valid line extract class name
            int wordpos = 0;
            p = strtok (fline, " ");

            while (p != NULL) {
                one_line_array[wordpos++] = p;
                p = strtok (NULL, " ");
            }

            char *cleaned = (char *) malloc(strlen(one_line_array[0]) );
            cleaned = one_line_array[0];

            if ((wordpos > 0) && (cleaned[0] == '.')) {
                cleaned++;
                if (cleaned[strlen(cleaned)-1] == ',') {
                    cleaned[strlen(cleaned)-1]  = 0;
                }

                // check for uniqueness

                int intc = (uintptr_t)*cindex;
                duplicate = 0;
                for ( i = 0; i < intc; i++ ) {
                    if ( strcmp(root_classes[i], cleaned) == 0 ) {
                        duplicate = 1;
                        break;
                    }
                }
                if (duplicate == 0) {
                root_classes[intc] = malloc(strlen(cleaned) + 1);
                strcpy(root_classes[intc], cleaned);
                (*cindex)++;
                }
               
            }

        }

    }
    fclose(fp);

    return 0;
}

