#include <stdlib.h>
#include <argp.h>

static char doc[] = "CSS CS Fixer scans for css files and analyse its usage";
static char args_doc[] = "path";
static struct argp_option options[] = {
  {"verbose",  'v', 0,      0,  "Produce verbose output" },
  {"quiet",    'q', 0,      0,  "Don't produce any output" },
  {"silent",   's', 0,      OPTION_ALIAS },
  {"output",   'o', "FILE", 0,
   "Output to FILE instead of standard output" },
  { 0 }
};
struct arguments
{
  char *args[1];
  int silent, verbose;
  char *output_file;
};

error_t parse_opt(int key, char *arg, struct argp_state *state);
static struct argp argp = { options, parse_opt, args_doc, doc };

