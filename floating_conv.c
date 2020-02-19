// C program to illustrate
// command line arguments
#include <stdio.h>
#include <stdlib.h>

float tofloat(char digit[]) {

    float result = 0;

    int offset = 0;
    int positive = 1;
    if (digit[0] == "-")
    {
        positive = 0;
        offset = 1;
    } else if (digit[0] == "+") offset = 1;

    int isDecimal = 0;
    float dec_digit = 0.1;

    for (int i = offset; digit[i] != '\0'; i++) 
    {
        if (digit[i] == ".") 
        {
            isDecimal = 1;
            continue;
        }
        printf("%d\n", isDecimal);
        if (isDecimal == 0)
        {
            result = result * 10 + digit[i] - '0';
            printf("%f\n", 1.0);
        } else
        {
            printf("%f\n", dec_digit * (digit[i] - '0'));
            result += dec_digit * (digit[i] - '0');
            dec_digit = dec_digit * 0.1;
        } 
    }
    if (positive == 0) result = -result;
    return result;
}

int main(int argc,char* argv[])
{
    int i;
    float value;
    if(argc != 2) 
    {
        printf("\nWrong number of command line arguments");
        exit(0);
    }
    printf("Program Name Is: %s\n", argv[0]);
    i = 0;
    while (argv[1][i] != '\0') 
    {
        printf("%c\n", argv[1][i]);
        i++;
    }
    value = tofloat(argv[1]);
    float value_alt = atof(argv[1]);
    printf("%f\n", value);
    printf("%f\n", value_alt);
    exit(0);
}