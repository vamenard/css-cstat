#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <limits.h>
#include <inttypes.h>
#include <stdint.h>

#include "util.h"
#include "grep.h"

int parse_root_entity( char path[], char *root_classes[], int *cindex, int verbose ) {

    if (verbose) {
        printf("Opening css file %s for analysis.\n", path);
    }

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
        newline = strchr(fline,'\n');
        if (newline != NULL) {
            *newline='\0';
        }

        if ((strstr(fline, "." ) !=NULL ) && ( strstr(fline, "{" ) !=NULL )  ) {
            
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


int build_css_xref( char *tpl[], int *tindex, char *root_classes[], int *cindex, int verbose) {

    int occ = 0, socc = 0;
    int c1 = 0, c2 = 0;
    char *analysis[1024][1014];

    for (c1 = 0; c1 < (*cindex); c1++) {

        for (c2 = 0; c2 < (*tindex); c2++) {
            socc = grep_single_file( tpl[c2], root_classes[c1], verbose);
            occ = occ + socc;
            socc = 0;
        }

        analysis[c1][0] = malloc(strlen( root_classes[c1] ) + 1);
        strcpy(analysis[c1][0], root_classes[c1]);

        char *pstr = itoa(occ, 10);
        if ((pstr != NULL) && (pstr[0] == '\0')) { 
            pstr = "0";
        } 
        analysis[c1][1] = malloc(strlen( pstr ) + 1);
        strcpy(analysis[c1][1], pstr);
        occ = 0;
    }
    for (c1 = 0; c1 < (*cindex); c1++) {
        printf("Class %s - %s occurences\n", analysis[c1][0], analysis[c1][1]);
    }
    
    return 1;
}

