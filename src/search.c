#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <limits.h>
#include <inttypes.h>
#include <stdint.h>

#include "util.h"
#include "search.h"

int file_search(const char *dir_name, char *files[], int *index, char *tpl[], int *tindex) {

    DIR *d;
    d = opendir(dir_name);

    if (!d) {
        fprintf (stderr, "Cannot open directory '%s': %s\n",dir_name, strerror (errno));
        exit (EXIT_FAILURE);
    }
    while (1) {
        struct dirent *entry;
        const char *d_name;
        entry = readdir (d);
        if (!entry) {
            break;
        }
        d_name = entry->d_name;
        if (!(entry->d_type & DT_DIR)) {
            if (strstr(d_name, ".css") != NULL) {

                if ((uintptr_t)*tindex < 255) { // prevent malloc exaustion
                    files[(uintptr_t)*index] = malloc(strlen(concat(dir_name, concat("/", d_name))) + 1);
                    strcpy(files[(uintptr_t)*index], concat(dir_name, concat("/", d_name)) );
                    (*index)++;
                }
	    }
            if ((strstr(d_name, ".html") != NULL) && (strstr(d_name, ".css") == NULL))  {
                if ((uintptr_t)*tindex < 255) { // prevent malloc exaustion

                    tpl[(uintptr_t)*tindex] = malloc(strlen(concat(dir_name, concat("/", d_name))) + 1);
                    strcpy(tpl[(uintptr_t)*tindex], concat(dir_name, concat("/", d_name)) );
                    (*tindex)++;

               }
            }
        }
        if (entry->d_type & DT_DIR) {
            
            if (strcmp (d_name, "..") != 0 &&
                strcmp (d_name, ".") != 0 &&
                strcmp(d_name, ".git") != 0) {
                int path_length;
                char path[PATH_MAX];
                path_length = snprintf (path, PATH_MAX,
                                        "%s/%s", dir_name, d_name);
                if (path_length >= PATH_MAX) {
                    fprintf (stderr, "Path length has got too long.\n");
                    exit (EXIT_FAILURE);
                }

                file_search(path, files, index, tpl, tindex);

            }
	}
    }
    if (closedir(d)) {
        fprintf (stderr, "Could not close '%s': %s\n",
                 dir_name, strerror (errno));
        exit (EXIT_FAILURE);
    }

    return 1;
    
}

