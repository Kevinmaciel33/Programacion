#ifndef MISFUNCIONES_H_INCLUDED
#define MISFUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void MI_MEMMOVE(void *dest, void *src, size_t n);
void MI_MEMCPY(void *dest, const void *src, size_t n);
int MI_ATOI(const char *str);
size_t MI_STRLEN(const char *str);
const char* MI_STRSTR(const char* s1, const char* s2);
char* MI_STRCPY(char *s1 ,const char* s2);
char * MI_STRCAT(char * s1, const char * s2);


#endif // MISFUNCIONES_H_INCLUDED
