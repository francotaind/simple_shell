#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
extern char **environ;
char *path_search(char *cmd);
char *string_combine(char *dest, char *src, int n);
int str_len(char *pointer);
char *strjoin(char *dest, char *src);
char *str_locater(char *s, char c);
void print_environ(void);
int string_compare(char *s1, char *s2);
char **parse_str(char *buffer);
#endif
