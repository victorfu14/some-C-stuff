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

unsigned long getMant(unsigned long val) {
    return (val << 12) >> 12; 
}

unsigned getExp(unsigned long val) {
    return (val << 1) >> 53;
}

unsigned getNeg(unsigned long val) {
    return (val >> 63);
}

void print_and_tofile(double val, unsigned long bits, unsigned long mantissa, unsigned exponent, unsigned negative, FILE *ptr) {
    fprintf(stdout, "The decimal value is %le.\n", val);
    fprintf(ptr, "The decimal value is %le.\n", val);
    fprintf(stdout, "The hexadecimal respresentation of the double value is 0x%lx.\n", bits);
    fprintf(ptr, "The hexadecimal respresentation of the double value is 0x%lx.\n", bits);
    fprintf(stdout, "The mantissa of the double value is 0x%lx.\n", mantissa);
    fprintf(ptr, "The mantissa of the double value is 0x%lx.\n", mantissa);
    int real_exponent = (int)exponent - 1023;
    fprintf(stdout, "The exponent of the double value is 0x%x, (with bias 1023) it's real value is %i.\n", exponent, real_exponent);
    fprintf(ptr, "The exponent of the double value is 0x%x, (with bias 1023) it's real value is %i.\n", exponent, real_exponent);
    if (negative) {
        fprintf(stdout, "The value is negative.\n");
        fprintf(ptr, "The value is negative.\n");
    } else {
        fprintf(stdout, "The value is positive.\n");
        fprintf(ptr, "The value is positive.\n");
    }
}

struct double_rep {
    union {
        double value;
        unsigned long int binary;
    } decimal;
    unsigned negative;
    unsigned exponent;
    unsigned long mantissa;
};

int main(int argc,char* argv[])
{
    int i;
    struct double_rep val;
    struct double_rep val_alt;
    FILE *fptr;
    fptr = fopen("double_conversion_output.txt", "a");
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
    val.decimal.value = todouble(argv[1]);
    val_alt.decimal.value = atof(argv[1]);
    union {
        double value;
        unsigned long binary;
    } diff;
    diff.value = val.decimal.value - val_alt.decimal.value;
    
    val.mantissa        = getMant(val.decimal.binary);
    val_alt.mantissa    = getMant(val_alt.decimal.binary);
    val.exponent        = getExp(val.decimal.binary);
    val_alt.exponent    = getExp(val_alt.decimal.binary);
    val.negative        = getNeg(val.decimal.binary);
    val_alt.negative    = getNeg(val.decimal.binary);

    fprintf(stdout, "This is the self-implemented conversion:\n");
    fprintf(fptr, "This is the self-implemented conversion:\n");
    print_and_tofile(val.decimal.value, val.decimal.binary, val.mantissa, val.exponent, val.negative, fptr);

    fprintf(stdout, "\nThis is the C atof() conversion:\n");
    fprintf(fptr, "\nThis is the C atof() conversion:\n");
    print_and_tofile(val_alt.decimal.value, val_alt.decimal.binary, val_alt.mantissa, val_alt.exponent, val_alt.negative, fptr);

    fprintf(stdout, "\nThe difference between the values is %le, and the hex representation is 0x%lx.\n", diff.value, diff.binary);
    fprintf(fptr, "\nThe difference between the values is %le, and the hex representation is 0x%lx.\n", diff.value, diff.binary);

    exit(0);
}