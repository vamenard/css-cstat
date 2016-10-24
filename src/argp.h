const char *argp_program_version = "programname programversion";
const char *argp_program_bug_address = "<your@email.address>";
static char doc[] = "Your program description.";
static char args_doc[] = "[FILENAME]...";
static struct argp_option options[] = { 
    { "line", 'l', 0, 0, "Compare lines instead of characters."},
    { "word", 'w', 0, 0, "Compare words instead of characters."},
    { "nocase", 'i', 0, 0, "Compare case insensitive instead of case sensitive."},
    { 0 } 
};

struct arguments {
    enum { CHARACTER_MODE, WORD_MODE, LINE_MODE } mode;
    bool isCaseInsensitive;
};

