/* read_double.c
 * ENSF 337 Lab 4 Exercise  E
 *
 */

#include "read_input.h"

int read_real(char* digits, int n, double * num)
{
    if(get_string(digits, n)== EOF)
        return EOF;

    if(is_valid_double(digits)){
        if(digits[0] == '-')
            *num = -convert_to_double(digits + 1);
        else if(digits[0] == '+')
            *num = convert_to_double(digits + 1);
        else
            *num = convert_to_double(digits);
        return 1;
    }

    return 0;
}

int is_valid_double(const char* digits)
{
    int valid = 1;
    int i, j=0,decimal =0;

    /* i = index where first digit should be */
    if(digits[0] == '+' || digits[0] == '-' || digits[0] == '.' )
        i = 1;
    else
        i = 0;

    /*check for decimal places*/
    while ( digits[j] != '\0')
    {
        if (digits[j] == '.')
            decimal++; j++;
    }

    /* Must have at least one digit, and no non-digits. */
    if (digits[i] == '\0')
        valid = 0;
    else
        while (valid && (digits[i] != '\0')) {
            if(digits[i] < '0' ||  digits[i] > '9' )
                valid = 0;
            if (digits[i] == '.')
                valid = 1;
            if (decimal > 1)
                valid =0;
            i++;
        }

    return valid;
}

double convert_to_double(const char *digits)
{
    int decimal_pos =0;
    int decimal_pres = 0;
    double sum  = 0;
    double sum_decimal =0;
    int i = 0;
    int j = 0;
    int power = 1;


    int len = 0;
    while(digits[len] != '\0')
    {
        len++;
    }

    while(digits[decimal_pos] != '\0')
    {
        if(digits[decimal_pos] == 46)
        {
            decimal_pres = 1;
            break;
        }
        decimal_pos++;

    }

    if (decimal_pres == 0)
    {
        while (digits[i] != '\0') {
            sum = 10 * sum + (digits[i] - '0');
            i++;
        }

    }
    else
    {
            while(digits[i] != 46) {
                sum= 10 * sum+ (digits[i] - '0');
                i++;
            }
            i++;
            j=i;
            while(digits[i] != '\0'){
                sum_decimal = 10 * sum_decimal + (digits[i] - '0');
                i++;
            }
            for(int k = 0; k < i-j; k++)
                power *= 10;
            sum_decimal = sum_decimal / power;
            sum = sum+ sum_decimal;

    }
    return sum;
}