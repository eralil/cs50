# include <cs50.h>
# include <stdio.h>


double multiply_float(float a,float b);

int main(void)
{

    float a = get_float("Enter input a: \n");
    float b = get_float("Enter input b: \n");

    printf("result : %.3f\n", multiply_float(a, b));
}

double multiply_float(float a,float b){
    return a * b;
}