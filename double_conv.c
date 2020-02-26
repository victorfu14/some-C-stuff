// C program to illustrate
// command line arguments
#include <stdio.h>
#include <stdlib.h>

double todouble(char digit[]) {
    double result = 0;
    int offset = 0;
    int positive = 1;
    if (digit[0] == '-')
    {
        positive = 0;
        offset = 1;
    } else if (digit[0] == '+') offset = 1;

    int isDecimal = 0;
    int ct = 0;
    double dec = 0.0;

    for (ct = offset; digit[ct] != '\0'; ct++) 
    {
        if (digit[ct] == '.') 
        {
            isDecimal = 1;
            continue;
        }
        if (isDecimal == 0)
        {
            result = result * 10 + digit[ct] - '0';
        }
    }
    if (isDecimal == 1)
    {
        for (ct = ct - 1; digit[ct] != '.'; ct--)
        {
            dec = (dec + digit[ct] - '0') * 0.1;
        }
    }
    result += dec;
    if (positive == 0) result = -result;
    return result;
}

int main(int argc,char* argv[])
{
    int i;
    union {
        double value;
        unsigned int hex;
    } val;
    union {
        double value;
        unsigned int hex;
    } val_alt;
    FILE *fptr;
    fptr = fopen("double_conversion_output.txt", "w");
    if(argc != 2) 
    {
        printf("\nWrong number of command line arguments");
        exit(0);
    }
    fprintf(stdout, "Program Name Is: %s\n", argv[0]);
    fprintf(fptr, "Program Name Is: %s\n", argv[0]);
    i = 0;
    while (argv[1][i] != '\0') 
    {
        fprintf(stdout, "%c\n", argv[1][i]);
        fprintf(fptr, "%c\n", argv[1][i]);
        i++;
    }
    val.value = todouble(argv[1]);
    val_alt.value = atof(argv[1]);
    double diff = val.value - val_alt.value;
    fprintf(stdout, "Self implemented conversion: %f\n", val.value);
    fprintf(fptr, "Self implemented conversion: %f\n", val.value);
    fprintf(stdout, "C conversion: %f\n", val_alt.value);
    fprintf(fptr, "C conversion: %f\n", val_alt.value);
    fprintf(stdout, "The difference is: %f\n", diff);
    fprintf(fptr, "The difference is: %f\n", diff);
    fprintf(stdout, "The hexadecimal respresentation of self implemented conversion is: %x\n", val.hex);
    fprintf(fptr, "The hexadecimal respresentation of self implemented conversion is: %x\n", val.hex);
    fprintf(stdout, "The hexadecimal respresentation of C atof conversion is: %x\n", val.hex);
    fprintf(fptr, "The hexadecimal respresentation of C atof conversion is: %x\n", val.hex);    
    exit(0);
}