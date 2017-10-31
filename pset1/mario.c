// This program prints a pyramid based on the user's selected height

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int h;

    // get a height input from user that is between 1 and 23
    do
    {
        h = get_int("Height of Pyramid: ");
    }
    while (h > 23 || h < 0);

    // iterate for h or height number of steps
    for (int i = 0; i <= h-1; i++)
    {
        // print initial spaces on left side of pyramid
        for (int a = h-i-1; a > 0; a--)
        printf(" ");

        // print left hashes
        for (int b = 0; b <= i; b++)
        printf("#");

        // print middle spaces
        printf("  ");

        // print right hashes
        for (int c = 0; c <= i; c++)
        printf("#");

        // go to next line
        printf("\n");
    }
}