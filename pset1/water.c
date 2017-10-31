// Program that determines the number of bottles of water based on the user's shower time

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // get user input of how long they shower
    int i = get_int("Minutes in Shower: ");

    // print number of bottles
    printf("Bottles of Water: %i\n", i * 12);
}