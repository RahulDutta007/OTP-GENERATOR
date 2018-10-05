#include <stdio.h>
#include <time.h>
#include <string.h>
char set[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
char otp[5];
int random();
void generate();
void output();
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
