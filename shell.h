#ifndef __SHELL_H__
#define __SHELL_H__
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
extern char **environ;
char *_getenv(const char *name);
int _puts(const char *str);
int _putchar(char c);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(const char *str);
int _strncmp(const char *str1, const char *str2, size_t n);
int word_count(char *s);
void central(char *str);
char **tokenize(char *str);
void execute(char *cmd, char **av);
char **path_list(char *path, char *cmd);
void free_malloc(char **str);
char *test_path(char **paths, char **cmd_list);
#endif /* __SHELL_H__ */
