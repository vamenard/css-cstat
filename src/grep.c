#include "grep.h"

int grep_single_file( char path[], char dummyclass[], int verbose ) {

    if (verbose) { 
        printf("\nOpening %s looking for %s\n", path, dummyclass);
    }
    char fline[100];
    char *newline;
    int count=0,occ=0;
    FILE *fp;

    fp = fopen(path,"r");

    while (fgets(fline,100,fp)!=NULL) {
        count++;
        newline = strchr(fline,'\n');
        if (newline != NULL) {
            *newline='\0';
        }
        if (strstr(fline, dummyclass )!=NULL) {
            printf("%s %d %s",path,count,fline);
            occ++;  
        }

    }
    fclose(fp);
    if (verbose) {
        printf("\%d Occurences found", occ);
    }
    return occ;
}
