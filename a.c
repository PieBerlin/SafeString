
#include<stdio.h>
#include<string.h>
int main(int argc,char* argv[]){
char str[8];
char *p;
if(argc<2)return -1;
p=argv[1];
strncpy(str,p,7);
printf("%s",str);
return 0;
}
