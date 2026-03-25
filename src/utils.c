#include <stdio.h>
#include "utils.h"

static int scene_counter = 1;

void reset_history_log(void) {
    FILE *f = fopen("history_log.txt", "w");
    if (f != NULL) {
        fclose(f);
    }
    scene_counter = 1;
}

void log_numeric_update(const char *name, double value) {
    FILE *f = fopen("history_log.txt", "a");
    if (f == NULL) return;
    fprintf(f, "Scene %d: Variable '%s' updated to %.6f\n", scene_counter++, name, value);
    fclose(f);
}

void log_string_update(const char *name, const char *value) {
    FILE *f = fopen("history_log.txt", "a");
    if (f == NULL) return;
    fprintf(f, "Scene %d: Variable '%s' updated to \"%s\"\n", scene_counter++, name, value);
    fclose(f);
}

void log_char_update(const char *name, char value) {
    FILE *f = fopen("history_log.txt", "a");
    if (f == NULL) return;
    fprintf(f, "Scene %d: Variable '%s' updated to '%c'\n", scene_counter++, name, value);
    fclose(f);
}