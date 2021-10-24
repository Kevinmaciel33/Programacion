#include "MisFunciones.h"

void MI_MEMMOVE(void *dest, void *src, size_t n)
{
    char *p_src = (char *)src;
    char *p_dest = (char *)dest;
    char temp[n+1];

    for (int i=0; i<n; i++)
        temp[i] = p_src[i];

    for (int i=0; i<n; i++)
        p_dest[i] = temp[i];

}
void MI_MEMCPY(void *dest, const void *src, size_t n)
{
    char *p_src = (char *)src;
    char *p_dest = (char *)dest;

    for (int i=0; i<n; i++)
        p_dest[i] = p_src[i];
}

int MI_ATOI(const char *str)
{
    return (*str - 48);
}

char MI_ITOA(int n)
{
//   char str[20];
//   sprintf(str, "%d", n);

    return (char)(n + 49);
}

size_t MI_STRLEN(const char *str)
{
    const char *s;

    for (s = str; *s; ++s);

    return (s - str);
}

const char* MI_STRSTR(const char* s1, const char* s2)
{
  for( ; *s1; ++s1 )
  {
    const char* cad1 = s2;
    for( const char* cad2 = s1; *cad1==*cad2 && *cad1; ++cad1, ++cad2);

    if( *cad1 == '\0' )
      return s1;
  }

  return NULL;
}

char* MI_STRCPY(char *s1 ,const char* s2)
{
    int i = 0;
    while((s1[i]= s2[i]) != '\0')
        i++;

    return s1;
}

char * MI_STRCAT(char * s1, const char * s2)
{
        char *p = s1;

        while (*s1)
               s1++;
        while ((*s1++ = *s2++) != '\0');

        return p;
}

