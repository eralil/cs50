#include <cs50.h>
#include <stdio.h>

int factorial_by_recursion(int n);
int factorial_by_multiplication(int n);

int main(void)
{
    int n = 0 ;
    do
    {
        n = get_int("number :\n");

    }
    while( n != 0 && n > 10);
    printf("%i! =  %i\n",n,factorial_by_recursion(n));
    printf("%i! =  %i\n",n,factorial_by_multiplication(n));
}

int factorial_by_recursion(int n)
{
    if( n == 1)
        return 1;
    else
        return n * factorial_by_recursion(n-1);
}

int factorial_by_multiplication(int n)
{
    int product = 1;
    for(int i = n ; i > 0 ; i--)
    {
        product *= i;
    }

    return product;
}