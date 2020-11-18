#include <cs50.h>
#include <stdio.h>

bool valid_triangle(float a,float b, float c);
int main(void)
{
    float a = get_float("Enter a:\n");
    float b = get_float("Enter b:\n");
    float c = get_float("Enter c:\n");

    printf("valid triangle ? %s\n", valid_triangle(a,b,c) == true?"true":"false");
}

bool valid_triangle( float a, float b, float c)
{
    unsigned int zero_check = 0;
    if(a > zero_check && b > zero_check && c > zero_check)
    {
        if((a + b ) > c || ( a + c ) > b || ( b + c) > a)
        {
            return true;
        }

    }

    return false;

}