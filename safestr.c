/* safestr.c */
#include "safestr.h"
//#include<string.h>
//#include<stdio.h>

void copy(void *dst,const void *src, const unsigned int n){
const char *psrc;
char  *pdst;
unsigned int x;
for (x=n,psrc=(const char *)src,pdst=( char *)dst;
	x; psrc++, pdst++,x--)
*pdst=*psrc;

return;
}
char *fold(String *str){
return str->data;

}


unsigned int length(const char *str){
int n;
const char *p;
for(n=0,p=str;*p;p++,n++){}


return n;
}


bool concat(String *dst,const char *src){

char *cp;

unsigned int n,cursize,size;
String *p;

n=length(src);
cursize=(dst->count+1)+sizeof(struct s_string);
size=cursize+n;

p=(String *)realloc(dst,size);
if(!p)return false;

cp=p->data+p->count;
copy(cp,src,n);
p->count+=n;

cp=p->data+p->count;
*cp=0;

return true;
}


String *init(const char *str){
unsigned int n, size;
String *p;

n=length(str);


size=(n+1)+sizeof(struct s_string);
p=(String *)malloc(size);
assert(p);

*p=(String){};

copy(p->data,str,n);
p->count=n;

return p;
}


int main(int argc,char *argv[]){

String *str;

char buf1[16],buf2[16];

str=init("Hello ");

//memset(buf1,0,16);
//memset(buf2,0,16);
//strncpy(buf1,"Hello you",15);
//memcpy(buf2,buf1,9);
//printf("'%s\n'",buf2);

//printf("length: %d\n",length("abct"));


printf("'%s'\n",str->data);

concat(str,"There");

printf("%s\n",fold(str));
uninit(str);

return 0;
}
