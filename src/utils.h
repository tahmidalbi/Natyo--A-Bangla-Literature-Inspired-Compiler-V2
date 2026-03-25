#ifndef UTILS_H
#define UTILS_H

void reset_history_log(void);
void log_numeric_update(const char *name, double value);
void log_string_update(const char *name, const char *value);
void log_char_update(const char *name, char value);

#endif