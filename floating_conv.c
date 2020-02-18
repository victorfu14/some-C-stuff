// C program to illustrate
// command line arguments
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
    int i;
    float value;
    if(argc!=2) {
        printf("\nWrong number of command line arguments");
        exit(0);
        }
    printf("Program Name Is: %s\n",argv[0]);
    i=0;
    while (argv[1][i] !='\0') {
        printf("%c\n",argv[1][i]);
        i++;
        }
    value=atof(argv[1]);
    printf("%f\n",value);
    exit(0);
}
