#include <argp.h>
#include <stdbool.h>

#include "argp.h"

static error_t parse_opt(int key, char *arg, struct argp_state *state) {
    struct arguments *arguments = state->input;
    switch (key) {
    case 'l': arguments->mode = LINE_MODE; break;
    case 'w': arguments->mode = WORD_MODE; break;
    case 'i': arguments->isCaseInsensitive = true; break;
    case ARGP_KEY_ARG: return 0;
    default: return ARGP_ERR_UNKNOWN;
    }   
    return 0;
}

