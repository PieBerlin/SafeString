/* safestr.h*/

#define _GNU_SOURCE
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<errno.h>

#define uninit(x)  free(x)

struct s_string{
 unsigned int count;
 char data[0];
 
};

typedef struct s_string String;

char *fold(String*);

void  copy(void *,const void*,const unsigned int);

unsigned int length(const char *);

String *init(const char*);
bool concat(String*,const char*);
int main(int, char**);

