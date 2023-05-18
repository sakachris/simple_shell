#ifndef __SHELL_H__
#define __SHELL_H__
#include <stdio.h>
#include <stdlib.h>
extern char **environ;
char *_getenv(const char *name);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(const char *str);
int _strncmp(const char *str1, const char *str2, size_t n);
int word_count(char *s);
#endif /* __SHELL_H__ */
