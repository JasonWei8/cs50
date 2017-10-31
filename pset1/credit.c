// This program uses Luhn's Algorithm to determine what type of credit card the user has based on the credit card number
// Works with American Express, Mastercard, and Visa

#include <stdio.h>
#include <cs50.h>
#include <math.h>


int main(void)
{
    // get credit card number from user
    long long number = get_long_long("Credit Card Number: ");

    // divide number by 10 to iterate later
    long long n = number/10;

    // initialize integer sumd
    int sumd = 0;

    // find the sum of each digit of the double of every second digit starting with n
    for (int i = 0; i <= 10; i++)
    {
        int doubledigit = (2 * ((long long)floor(n/pow(100,i)) % 10)) % 10 + (long long)floor((2 * ((long long)floor(n
                            /pow(100,i)) % 10))/10) % 10;
        sumd += doubledigit;
    }

    // find the sum of the digits that weren't added in previous step and add to previous sum
    for (int i = 0; i <= 10; i++)
    {
        int singledigit = (long long)floor(number/pow(100,i)) % 10;
        sumd += singledigit;
    }

    printf("Your Credit Card is: ");

    // check if last digit of total sum is 0
    if (sumd % 10 == 0)
    {
        // if last digit of total sum is 0 check to see which type of card the input number was
        if ((340000000000000 <= number && number < 350000000000000) ||
                    (370000000000000 <= number && number < 380000000000000))
            printf("AMEX\n");

        else if (5100000000000000 <= number && number < 5600000000000000)
            printf("MASTERCARD\n");

        else if ((4000000000000 <= number && number < 5000000000000) ||
                    (4000000000000000 <= number && number < 5000000000000000))
            printf("VISA\n");
    }

    // invalid if last digit of sum is not 0 or if number did not match card type check
    else
    printf("INVALID\n");
}
