#ifndef __SHELL_H__
#define __SHELL_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
extern char **environ;
char *_getenv(const char *name);
void print_counter(int num);
int _putchar(char c);
int _putchar_err(char c);
int _strcmp(char *s1, char *s2);
int _puts(const char *str);
int _puts_err(const char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(const char *str);
int _strncmp(const char *str1, const char *str2, size_t n);
int word_count(char *s);
/*void central(char *str);*/
void free_malloc(char **str);
char *testing_path(char **paths, char **cmd_list);
void cmd_not_found(char **av, int counter, char **cmd_list);
void built_it(char **cmd, char *str);
char **tokensize(char *str);
void execute_cmd(char *cmd, char **av);
char **path_list(char *path, char *cmd);
#endif /*__MY_SHELL_H__ */
